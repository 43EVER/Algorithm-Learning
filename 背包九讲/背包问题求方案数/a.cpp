#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int dp1[MAXN], dp2[MAXN];

// 求方案，感觉可以扩展到其他背包问题求方案数
// 两个点，初始化为 dp1 除 0 其他初始化为 INF，让状态只能由 0 转移过去，使得体积刚好为 v 时，最大价值是多少
// dp2[0] 初始化为 1，转移的时候注意下
// 算完以后，可能有多个体积的最大价值都是 最大价值，方案数需要再统计一下

int main() {
    int N, V;
    cin >> N >> V;
    dp2[0] = 1;
    dp1[0] = 0;
    for (int i = 1; i <= V; i++) dp1[i] = -INF;
    int v, w;
    for (int i = 0; i < N; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            int t = max(dp1[j], dp1[j - v] + w);
            int s = 0;
            if (t == dp1[j]) s = dp2[j] % MOD;
            if (t == dp1[j - v] + w) s = (s + dp2[j - v]) % MOD;
            
            dp1[j] = t;
            dp2[j] = s;
        }
    }

    int idx = max_element(dp1, dp1 + V + 1) - dp1;
    int res = 0;
    for (int i = 0; i <= V; i++) if (dp1[i] == dp1[idx]) res = (res + dp2[i]) % MOD;

    cout << res << endl;
}