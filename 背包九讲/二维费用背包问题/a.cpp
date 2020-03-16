#include <iostream>
using namespace std;

class Solver {
    // 体积重量都有限制
    // 还是一样，一个物体只可能选或者不选

    static const int MAXN = 100 + 5;
    int dp[MAXN][MAXN] = {};
    int V, M;

    void zeroOnePack(int v, int m, int w) {
        for (int i = V; i >= v; i--)
            for (int j = M; j >= m; j--)
                dp[i][j] = max(dp[i][j], dp[i - v][j - m] + w);
    }

public:
    void f() {
        int N;
        cin >> N >> V >> M;
        int v, m, w;
        while (N--) {
            cin >> v >> m >> w;
            zeroOnePack(v, m, w);
        }
        cout << dp[V][M] << endl;
    }
};

int main() {
    Solver s;
    s.f();
}