#include <iostream>
#include <queue>
using namespace std;

const int N = 1000 + 5;

int mm[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int mp2[N][N];
char mp1[N][N];
int n, m;

int main() {
    while (cin >> n >> m) {
        queue<int> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> mp1[i][j];
                if (mp1[i][j] == '1') {
                    q.push(i);
                    q.push(j);
                    q.push(0);
                    mp2[i][j] = 0;
                }
                else mp2[i][j] = -1;
            }

        while (q.size()) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            int t = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + mm[i][0];
                int ny = y + mm[i][1];
                int nt = t + 1;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp2[nx][ny] == -1) {
                    mp2[nx][ny] = nt;
                    q.push(nx);
                    q.push(ny);
                    q.push(nt);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << mp2[i][j] << " ";
            cout << endl;
        }
    }
}