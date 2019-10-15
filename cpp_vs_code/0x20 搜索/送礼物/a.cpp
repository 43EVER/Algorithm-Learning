#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 50, INF = 0x3f3f3f3f;
long long g[N], w;
long long a[1 << 24];
long long ans = -INF;
int cnt = 0;
int n;

void dfs1(int dep, long long sum) {
    if (dep > n/2 + 2) {
        a[++cnt] = sum;
        return;
    }
    dfs1(dep + 1, sum);
    if (sum + g[dep] <= w)
        dfs1(dep + 1, sum + g[dep]);
}

void dfs2(int dep, long long sum) {
    if (dep > n) {
        auto p  = lower_bound(a + 1, a + cnt + 1, w - sum, [](int a, int b) {
            return a > b;
        });
        if (p != a + cnt + 1) ans = max(ans, sum + *p); 
        return;
    }
    dfs2(dep + 1, sum);
    if (sum + g[dep] <= w)
        dfs2(dep + 1, sum + g[dep]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> w >> n) {
        for (int i = 1; i <= n; i++) cin >> g[i];
        sort(g + 1, g + n + 1, greater<long long>());
        dfs1(1, 0);
        sort(a + 1, a + 1 + cnt, greater<long long>());
        cnt = unique(a + 1, a + 1 + cnt) - a;
        dfs2(n/2 + 3, 0);
        cout << ans << endl;

        memset(g, 0, sizeof(g));
    }
}