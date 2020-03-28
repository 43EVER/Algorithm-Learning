#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int ans = 0x3f3f3f3f;
int r[25], h[25];
int minV[25], minS[25];
int v, s;

void dfs(int dep) {
    // cout << dep << " " << v << " " << s << endl;

    if (dep == 0) {
        if (v == n) ans = min(ans, s);
        return;
    }
    if (v + minV[dep] > n) return;
    if (s + minS[dep] > ans) return;

// for (r[dep] = min((int)sqrt(n - v), r[dep + 1] - 1); r[dep] >= dep; r[dep]--)/*确定半径*/
//         for (h[dep] = min((int)((double)(n-v) / r[dep] / r[dep]), h[dep+1] - 1); h[dep] >= dep; h[dep]--)

    for (r[dep] = min( (int)sqrt(n - v), r[dep + 1] - 1 ); r[dep] >= dep; r[dep]--)
        for (h[dep] = min( (int)((double(n-v)) / r[dep] / r[dep] ), h[dep + 1] - 1); h[dep] >= dep; h[dep]--) {
            if (s + 2.0 * (n - v) / r[dep] > ans) continue;
            v += r[dep] * r[dep] * h[dep];
            s += 2 * r[dep] * h[dep];
            if (dep == m)
                s += r[dep] * r[dep];
            dfs(dep - 1);
             v -= r[dep] * r[dep] * h[dep];
            s -= 2 * r[dep] * h[dep];
            if (dep == m)
                s -= r[dep] * r[dep];
        }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        minV[i] = minV[i - 1] + i * i * i;
        minS[i] = minS[i - 1] + 2 * i * i;
    }

    r[m + 1] = h[m + 1] = INF;
    dfs(m);

    cout << ans << endl;
}