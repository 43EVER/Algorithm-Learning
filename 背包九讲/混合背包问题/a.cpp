#include <iostream>
using namespace std;

class PackSolver {
    static const int MAXN = 1000 + 5;
    struct Node {
        int pos, val;
    } q[MAXN];
    int dp[MAXN] = {};
    int N, V;

    void zeroOnePack(int v, int w) {
        for (int i = V; i >= v; i--)
            dp[i] = max(dp[i], dp[i - v] + w);
    }

    void completePack(int v, int w) {
        for (int i = v; i <= V; i++)
            dp[i] = max(dp[i], dp[i - v] + w);
    }

    // 多重背包 N*V
    void multiPack(int v, int w, int s) {
        for (int i = 0; i < v; i++) {
            int hh = 0, tt = 0, stop = (V-i)/v;
            for (int k = 0; k <= stop; k++) {
                int val = dp[k*v+i] - k * w;
                while (hh < tt && q[tt - 1].val <= val) tt--;
                if (hh < tt && k - q[hh].pos > s) hh++;
                q[tt].val = val, q[tt++].pos = k;
                dp[k*v+i] = q[hh].val + k*w;
            }
        }
    }

    // 多重背包 N*V*LogS
    void multiPack(int v, int w, int s, bool) {
        for (int i = 1; i <= s; s -= i, i *= 2) zeroOnePack(v * i, w * i);
        if (s) zeroOnePack(v * s, w * s);
    }

public:
    void f() {
        cin >> N >> V;
        int v, w, s;
        while (N--) {
            cin >> v >> w >> s;
            if (s == -1) zeroOnePack(v, w);
            else if (s == 0) completePack(v, w);
            else multiPack(v, w, s);
        }
        cout << dp[V] << endl;
    }
};

int main() {
    PackSolver s;
    s.f();
}