#include <iostream>
#include <vector>
using namespace std;

class Solver {
    static const int MAXN = 100 + 5;
    struct Edge {
        int idx;
        int v, w;
        int last;
    } edges[MAXN];

    int dp[MAXN][MAXN] = {};
    
    int cnt = 0, head[MAXN];
    int N, V;
    int root = 0;
    
    void addEdge(int v, int w, int fa, int idx) {
        if (fa == -1) fa = 0;
        edges[cnt] = {idx, v, w, head[fa]};
        head[fa] = cnt++;
    }

    void dfs(int idx) {
        for (int e = head[idx]; e != -1; e = edges[e].last) {
            Edge edge = edges[e];
            dfs(edge.idx);
            for (int i = V; i >= edge.v; i--) dp[edge.idx][i] = dp[edge.idx][i - edge.v] + edge.w;
            for (int i = 0; i < edge.v; i++) dp[edge.idx][i] = 0;
            for (int i = V; i >= 0; i--)
                for (int j = i; j >= 0; j--)
                    dp[idx][i] = max(dp[idx][i], dp[idx][i - j] + dp[edge.idx][j]);
        }
    }

public:
    Solver() {
        cin >> N >> V;
        for (int i = 0; i <= N; i++) head[i] = -1;
        int v[MAXN], w[MAXN], fa[MAXN];
        for (int i = 1; i <= N; i++) {
            cin >> v[i] >> w[i] >> fa[i];
            if (fa[i] == -1) root = i;
        }
        for (int i = 1; i <= N; i++) addEdge(v[i], w[i], fa[i], i);
        
        // for (int i = 0; i <= N; i++) {
        //     cout << "root: " << i << endl;
        //     for (int e = head[i]; e != -1; e = edges[e].last) {
        //         cout << edges[e].v << " " << edges[e].w << endl;
        //     }
        //     cout << "------------" << endl;
        // }

        dfs(0);
        
        cout << dp[0][V];
    }
};

// 大概思路，看成分组背包问题，dp[i][j] 表示以 i 为根的子树，体积为 j 时的最大价值
// 选的时候，可以把子节点所有的 j 看成一组，N 组里面，组内互斥
/*
    建好树以后，从根节点开始，递归算
    每次先算完子节点的所有体积对应的最大价值，然后把每个子节点（直接子节点）看成一组，变成分组背包
    注意一点，某一个节点选完以后，自己也要选，而且选不了自己的状态没有意义，要变 0
*/

class Solver2 {
    static const int MAXN= 100 + 5;
    
    int v[MAXN], w[MAXN];
    vector<int> g[MAXN];
    int N, V;
    int dp[MAXN][MAXN] = {};


    // 更好理解的一种转移
    // 一开始，默认所有 [v[x], V] 是选了 w[x]的
    // 之后算完子节点后，进行枚举时，j 应该在 [V, v[x]] 里，因为 小于 v[x] 的 j 非法
    // 而枚举组内物品时，组内物品体积需要在 [0, j - v[x]] 里，如果超出，则说明不能选 v[x]，不合法
    void dfs(int idx) {
        for (int i = v[idx]; i <= V; i++) dp[idx][i] = w[idx];
        for (auto sub : g[idx]) {
            dfs(sub);
            for (int j = V; j >= v[idx]; j--)
                for (int k = 0; k <= j - v[idx]; k++)
                    dp[idx][j] = max(dp[idx][j], dp[idx][j - k] + dp[sub][k]);
        }
    }

    // 原版转移方式，子节点算完以后，在 [V - v[x], 0] 进行枚举，因为在这范围内枚举，才是能选 子节点的状态，而 [v[x], V] 会在子节点选完后，最后选
    // 每个节点算完以后，因为只是转移完，还没有把自己加上去，所以得在最后加上根节点
    // 加上根节点时，为什么从大到小，从小到大会使用已经加过根节点的状态
    // 为什么要把 [0, v[x] - 1] 赋成 0，不这样做会导致从非法状态转移
    void dfs2(int x) {
        for (auto y : g[x]) {
            dfs(y);
            for (int j = V - v[x]; j >= 0; j--)
                for (int k = j; k >= 0; k--)
                    dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[y][k]);
        }
        for (int i = V; i >= v[x]; i--) dp[x][i] = dp[x][i - v[x]] + w[x];
        for (int i = 0; i < v[x]; i++) dp[x][i] = 0;
    }

public:
    void f() {
        cin >> N >> V;
        int root, fa;
        for (int i = 1; i <= N; i++) {
            cin >> v[i] >> w[i] >> fa;
            if (fa == -1) root = i;
            else g[fa].push_back(i);
        }
        dfs2(root);
        cout << dp[root][V] << endl;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= V; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Solver2 s;
    s.f();
}