#include <iostream>
#include <queue>
using namespace std;
 
const int MAX = 100 + 5;
char maps[MAX][MAX];
int mm[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int m, n;

int bfs(int si, int sj) {
    queue<int> q;
    bool mark[MAX][MAX] = {};
 
    q.push(si);
    q.push(sj);
    mark[si][sj] = true;
 
    while (!q.empty()) {
        int curi = q.front(); q.pop();
        int curj = q.front(); q.pop();
 
        if (maps[curi][curj] == 'P')
            return true;
 
        for (int i = 0; i < 4; i++) {
            int nexti = curi + mm[i][0];
            int nextj = curj + mm[i][1];
 
            if (nexti >= 0 && nexti < m && nextj >= 0 && nextj < n && mark[nexti][nextj] == false && maps[nexti][nextj] != '*') {
                q.push(nexti);
                q.push(nextj);
                mark[nexti][nextj] = true;
            }
        }
    }
 
    return false;
}
 
 
int main() {
    while (cin >> n >> m && m) {
        for (int i = 0; i < m; i++)
            cin >> maps[i];
 
        int si = -1, sj = -1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (maps[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
 
        bool ok = bfs(si, sj);
 
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}