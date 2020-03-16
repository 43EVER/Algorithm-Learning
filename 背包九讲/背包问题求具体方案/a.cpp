#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000 + 5;

int dp[MAXN][MAXN];

int main() {
    int N, V;
    cin >> N >> V;
    int v[MAXN], w[MAXN];
    for (int i = 1; i <= N; i++) cin >> v[i] >> w[i];
    
    for (int i = N; i >= 1; i--)
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }

    int val = V;
    for (int i = 1; i <= N; i++) {
        if (!val) {
            break;
        } else if (val - v[i] >= 0 && dp[i][val] == dp[i + 1][val - v[i]] + w[i]) {
            cout << i << " ";
            val -= v[i];
        }
    }
}