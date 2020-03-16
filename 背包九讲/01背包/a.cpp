#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;

class Solver1 {
/*
f[i][j] 表示 只看前 i 个物品，背包大小为 j 时的最大价值
result = max(f[n][0-v])
f[i][j]:
    1. 不选 i ，f[i][j] = f[i - 1][j]
    2. 选 i ，f[i][j] = f[i - 1][j - w[i]] + v[i]
f[0][0] = 0
*/
    const static int MAXN = 1000 + 5;
    int dp[MAXN][MAXN];
    int w[MAXN], v[MAXN];

public:
    void f() {
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++)
            cin >> v[i] >> w[i];
        
        for (int i = 1; i <= N; i++)
            for (int j = 0; j <= V; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= v[i])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        cout << dp[N][V] << endl;
    }
};

class Solver2 {
    /*
    一维优化
    */
    static const int MAXN = 1000 + 5;
    
    int v[MAXN], w[MAXN];
    int dp[MAXN] = {};

public:
    void f() {
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++)
            cin >> v[i] >> w[i];
        
        for (int i = 1; i <= N; i++)
            for (int j = V; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        
        cout << dp[V] << endl;
    }
};

class Solver3 {
    static const int MAXN = 1000 + 5;
    static const int INF = 0x3f3f3f3f;

    int v[MAXN], w[MAXN];
    int dp[MAXN];

public:
    void f() {
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++)
            cin >> v[i] >> w[i];
        
        dp[0] = 0;
        for (int i = 1; i <= V; i++) dp[i] = -INF;
        for (int i = 1; i <= N; i++)
            for (int j = V; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        
        cout << *max_element(dp, dp + V + 1) << endl;
    }
};

int main() {
    Solver1 s1;
    Solver2 s2;
    Solver3 s3;

    srand(time(NULL));
    int tmp = rand() % 3;
    if (tmp == 0) s1.f();
    else if (tmp == 1) s2.f();
    else s3.f();
}