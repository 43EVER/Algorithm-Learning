#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const int N = 16, M = N * N + 1;
int cnt[1 << N], num[1 << N];

vector<vector<int> > state(N, vector<int>(N));
vector<vector<vector<int> > > bstate(M, state), bstate2(M, state);

vector<string> str(N);
vector< vector<string> > bstr(M, str);

void draw(int x, int y, int k) {
    str[x][y] = k + 'A';
    for (int i = 0; i < N; i++) state[x][i] &= ~(1 << k), state[i][y] &= ~(1 << k);
    int sx = x/4*4, sy = y/4*4;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) state[sx + i][sy + j] &= ~(1 << k);
    state[x][y] = 1 << k;
}

bool dfs(int dep) {
    if (!dep) return true;

    int bdep = dep;
    bstate[dep] = state;
    bstr[dep] = str;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (str[i][j] == '-') {
        if (!state[i][j]) {
            state = bstate[bdep];
            str = bstr[bdep];
            return false;
        } else if (num[state[i][j]] == 1) {
            draw(i, j, num[state[i][j]]);
            dep--;
        }
    }
    if (!dep) return true;

    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; j++) {
            int s = state[i][j];
            sand &= ~(s & sor);
            sor |= s;
            if (str[i][j] != '-') drawn |= state[i][j];
        }
        if (sor != (1 << N) - 1) {
            state = bstate[bdep];
            str = bstr[bdep];
            return false;
        }
        for (int j = sand; j; j -= j&-j) {
            int t = j&-j;
            if (!(t & drawn)) for (int k = 0; k < N; k++) {
                if (state[i][k] & t) {
                    draw(i, k, num[t]);
                    dep--;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        for (int j = 0; j < N; j++) {
            int s = state[j][i];
            sand &= ~(s & sor);
            sor |= s;
            if (str[j][i] != '-') drawn |= state[j][i];
        }
        if (sor != (1 << N) - 1) {
            state = bstate[bdep];
            str = bstr[bdep];
            return false;
        }
        for (int j = sand; j; j -= j&-j) {
            int t = j&-j;
            if (!(t & drawn)) for (int k = 0; k < N; k++) {
                if (state[k][i] & t) {
                    draw(k, i, num[t]);
                    dep--;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int sor = 0, sand = (1 << N) - 1;
        int drawn = 0;
        int sx = i/4*4, sy = i%4*4;
        for (int j = 0; j < N; j++) {
            int dx = j/4, dy=j%4;
            int s = state[sx + dx][sy + dy];
            sand &= ~(s & sor);
            sor |= s;
            if (str[sx + dx][sy + dy] != '-') drawn |= state[sx + dx][sy + dy];
        }
        if (sor != (1 << N) - 1) {
            state = bstate[bdep];
            str = bstr[bdep];
            return false;
        }
        for (int j = sand; j; j -= j&-j) {
            int t = j&-j;
            if (!(t & drawn)) for (int k = 0; k < N; k++) {
                int dx = k / 4, dy = k % 4;
                if (state[sx + dx][sy + dy] & t) {
                    draw(sx + dx, sy + dy, num[t]);
                    dep--;
                    break;
                }
            }
        }
    }
    if (!dep) return true;

    int x, y, tmp = 20;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (str[i][j] == '-' && cnt[state[i][j]] < tmp)
        x = i, y = j, tmp = cnt[state[i][j]];
    bstate2[bdep] = state;
    for (int i = state[x][y]; i; i -= i&-i) {
        state = bstate2[bdep];
        draw(x, y, num[i&-i]);
        if (dfs(dep - 1)) return true;
    }

    state = bstate2[bdep];
    str = bstr[bdep];
    return false;
}

int main() {
    for (int i = 0; i < 1 << N; i++) for (int j = i; j; j -= j&-j) cnt[i]++;
    for (int i = 0; i < N; i++) num[1 << i] = i;

    while (cin >> str[0]) {
        for (int i = 1; i < N; i++) cin >> str[i];
        
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) state[i][j] = (1 << N) - 1;
        int dep = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            if (str[i][j] == '-') dep++;
            else draw(i, j, str[i][j] - 'A');
        
        dfs(dep);

        for (int i = 0; i < N; i++) cout << str[i] << endl;
        cout << endl;
    }
}