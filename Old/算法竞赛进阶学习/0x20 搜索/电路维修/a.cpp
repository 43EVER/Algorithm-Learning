#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

const int N = 500 + 5;
typedef pair<int, int> PII;
char str[N][N];
int vis[N][N];
int n, m;

int dx1[] = {0, -1, 0, -1}, dy1[] = {0, 0, -1, -1};
int dx2[] = {1, -1, 1, -1}, dy2[] = {1, 1, -1, -1};
string d = "\\//\\";

bool is_valid(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> str[i];
        memset(vis, 0x3f, sizeof(vis));
        deque<PII> q;
        q.push_back({0, 0});
        vis[0][0] = 0;
        while (q.size()) {
            PII cur = q.front(); q.pop_front();
            int i = cur.first, j = cur.second;
            // cout << i << " " << j << " " << vis[i][j] << endl;
            if (i == n && j == m) break;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx1[k], nj = j + dy1[k];
                if (is_valid(ni, nj)) {
                    int ii = i + dx2[k], jj = j + dy2[k];
                    // cout << "|" << ii << " " << jj << " " << str[ni][nj] << " " << k << " " << ni << " " << nj << "|" << endl;
                    if (vis[ii][jj] > vis[i][j])
                        if (str[ni][nj] == d[k]) vis[ii][jj] = vis[i][j], q.push_front({ii, jj});
                        else vis[ii][jj] = vis[i][j] + 1, q.push_back({ii, jj});
                }
            }
        }
        if (vis[n][m] == 0x3f3f3f3f) cout << "NO SOLUTION" << endl;
        else cout << vis[n][m] << endl;
    }
}