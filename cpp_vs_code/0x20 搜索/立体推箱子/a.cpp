#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 500 + 5;

struct Node {
    int x, y, fx; // r d t
    int step;
};

int mm[3][4][3] = {     // d, r, t
    {
        {-1, 0, 2},
        {0, 1, 0},              // 上右下左
        {2, 0, 2},
        {0, -1, 0}
    },
    {
        {-1, 0, 1},
        {0, 2, 2},
        {1, 0, 1},
        {0, -1, 2}
    },
    {
        {-2, 0, 0},
        {0, 1, 1},
        {1, 0, 0},
        {0, -2, 1}
    }
};

char str[N][N];
bool vis[3][N][N];
int n, m;

bool isvalid2(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && str[x][y] !='#') return true;
    return false;
}

bool isvalid(const Node & cur) {
    if (isvalid2(cur.x, cur.y) && !vis[cur.fx][cur.x][cur.y]) {
        if (cur.fx == 0 && isvalid2(cur.x + 1, cur.y)) return true;
        else if (cur.fx == 1 && isvalid2(cur.x, cur.y + 1)) return true;
        else if (cur.fx == 2 && str[cur.x][cur.y] != 'E') return true;
    }
    return false;
}

int bfs(Node s) {
    queue<Node> q;
    s.step = 0;
    q.push(s);
    vis[s.fx][s.x][s.y] = true;
    while (q.size()) {
        Node cur = q.front(); q.pop();
        if (cur.fx == 2 && str[cur.x][cur.y] == 'O')
            return cur.step;
        for (int i = 0; i < 4; i++) {
            Node next = {cur.x + mm[cur.fx][i][0], cur.y + mm[cur.fx][i][1], mm[cur.fx][i][2], cur.step + 1};
            if (isvalid(next)) {
                q.push(next);
                vis[next.fx][next.x][next.y] = true;
            }
        }
    }
    return -1;
}

int main() {
    while (cin >> n >> m && n) {
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++)
            cin >> str[i];
        Node s;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < m; j++)
                if (str[i][j] == 'X') {
                    s.x = i, s.y = j, s.fx = 2;
                    if (i + 1 < n && str[i + 1][j] == 'X')
                        s.fx = 0;
                    else if (j + 1 < m && str[i][j + 1] == 'X')
                        s.fx = 1;
                    ok = true;
                    break;
                }
            if (ok) break;
        }
        int step = bfs(s);
        if (step == -1) cout << "Impossible" << endl;
        else cout << step << endl;
    }
}