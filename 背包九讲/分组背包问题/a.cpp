#include <iostream>
#include <algorithm>
using namespace std;

class Solver {
    static const int MAXN = 100 + 5;
    static const int INF = 0x3f3f3f3f; 
    int dp[MAXN] = {}, v[MAXN], w[MAXN];
    int V, n;

    void zeroOnePack() {
        for (int i = V; i >= 0; i--) {
            for (int j = 0; j < n; j++) 
                if (i >= v[j]) dp[i] = max(dp[i], dp[i - v[j]] + w[j]);
        }
    }

public:
    void f() {
        int N;
        cin >> N >> V;
        while (N--) {
            cin >> n;
            for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
            zeroOnePack();
        }
        cout << dp[V] << endl;
    }
};

int main() {
    Solver s;
    s.f();
}