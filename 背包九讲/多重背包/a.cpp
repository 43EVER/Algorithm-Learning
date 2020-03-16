#pragma GCC optimize(2)

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Solver {
    // 野路子
    static const int MAXN = 20000 + 10;
    int dp[MAXN] = {};
    
    void zeroOnePack(int v, int w) {
        for (int j = V; j >= v; j--)
            dp[j] = max(dp[j], dp[j - v] + w);
    }

    void completePack(int v, int w) {
        for (int j = v; j <= V; j++)
            dp[j] = max(dp[j], dp[j - v] + w);
    }

    void multiPack(int v, int w, int s) {
        if (v * s >= V) {
            completePack(v, w);
        } else {
            for (int k = 1; k <= s; k <<= 1) {
                zeroOnePack(v * k, w * k);
                s -= k;
            }
            if (s) zeroOnePack(v * s, w * s);
        }
    }

public:
    int N, V;

    void f() {
        cin >> N >> V;
        for (int i = 1; i <= N; i++) {
            int v, w, s;
            cin >> v >> w >> s;
            multiPack(v, w, s);
        }
        cout << dp[V] << endl;
    }
};

// 单调队列优化版本
/* 
总共 N 个物品，背包体积为 V
每个物品的体积是 v，价值是 w，数量是 s

思路：
    原始方程：f[i][j] = max(f[i - 1][j], f[i - 1][j - kv] + kw) (0 <= k <= j/v)
    一维优化后：f[j] = max(g[j - kv] + kw) (0 <= k <= j / v)
    其实可以分组，即对每一个数据为 v, w, s 的物品，进行枚举时，利用 j % v，把 V 分成 v 组
    假设对于首项为0的那组：
        f[0] = f[0]
        f[v] = f[v], f[v - v] + w = f[v], f[0] + w
        f[2v] = f[2v], f[2v - v] + w, f[2v - 2v] + 2w = f[2v], f[v] + w, f[0] + 2w
        ...
        f[kv] = f[kv], f[(k - 1)v] + w, ..., f[0] + kw
    可以转换成
        f[0] - 0w       = f[0]
        f[v] - 1w       = f[v] - w, f[0]
        f[2v] - 2w      = f[2v] - 2w, f[v] - w, f[0]
        ...
        f[kv] - kw      = f[kv] - kw, f[(k-1)v] - (k-1)w, ..., f[0]
    这样就可以用单调队列去维护了，只要在最后的结果那加 kw 就好
*/
class Solver2 {
    static const int MAXN = 20000 + 5;
    struct Node {
        int pos, val;
    } q[MAXN];
    int dp[MAXN] = {};
    int N, V;
    void multiPack(int v, int w, int s) {
        for (int i = 0; i < v; i++) {
            int hh = 0, tt = 0, stop = (V - i) / v;
            for (int k = 0; k <= stop; k++) {
                int val = dp[k * v + i] - k * w;
                while (hh < tt && q[tt - 1].val <= val) tt--;
                if (hh < tt && q[hh].pos < k - s ) hh++;
                q[tt].val = val, q[tt++].pos = k;
                dp[k * v + i] = q[hh].val + k*w;
            }
        }
    }
public:
    void f() {
        cin >> N >> V;
        int v, w, s;
        for (int i = 0; i < N; i++) {
            cin >> v >> w >> s;
            multiPack(v, w, s);
        }
        cout << dp[V] << endl;
    }
};

int main() {
    Solver2 s;
    s.f();
}