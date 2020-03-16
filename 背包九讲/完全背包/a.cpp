#include <iostream>
#include <functional>
using namespace std;

class Solver1 {
    static const int MAXN = 1000 + 10;
    const int INF = 0X3f3f3f3f;
    int v[MAXN], w[MAXN];
    int dp[MAXN] = {};

public:
    void f() {
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++) cin >> v[i] >> w[i];
        for (int i = 1; i <= N; i++) 
            for (int j = v[i]; j <= V; j++)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        cout << dp[V] << endl;
    }

    void f2() {
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++) cin >> v[i] >> w[i];
        for (int i = 1; i <= N; i++)
            for (int j = V; j >= v[i]; j--)
                for (int k = 0; k * v[i] <= j; k++)
                    dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);

        cout << dp[V] << endl;
    }

    void f3() {
        int N, V;
        cin >> N >> V;
        for (int i = 1; i <= N; i++) cin >> v[i] >> w[i];
        dp[0] = 0;
        for (int i = 1; i <= V; i++) dp[i] = -INF;

        for (int i = 1; i <= N; i++)
            for (int j = v[i]; j <= V; j++)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

        cout << *max_element(dp + 1, dp + 1 + V) << endl;
    }
};

int main() {
    Solver1 s;
    s.f3();
}