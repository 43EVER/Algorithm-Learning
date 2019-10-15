#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
    int city;
    int cost;
    int left_fuel;

    friend bool operator< (const Node & a, const Node & b) {
        return a.cost > b.cost;
    }
};
const int N = 1000 + 10;

struct Edge {
    int v, w;
    int next;
} edges[20000 + 20];
int cnt = 0;
int head[N];

void add_edge(int u, int v, int w) {
    edges[++cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

bool vis[N][100 + 5];

int a[N];

int bfs(int c, int s, int t) {
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> q;
    q.push({s, 0, 0});
    vis[s][0] = true;

    while (q.size()) {
        Node cur = q.top(); q.pop();
        // cout << cur.city << " " << cur.left_fuel << " " << cur.cost << endl;
        if (cur.city == t) return cur.cost;

        if (cur.left_fuel + 1 <= c && !vis[cur.city][cur.left_fuel + 1]) q.push({cur.city, cur.cost + a[cur.city], cur.left_fuel + 1});
        for (int i = head[cur.city]; i; i = edges[i].next) {
            Node next = {edges[i].v, cur.cost, cur.left_fuel - edges[i].w};
            if (next.left_fuel >= 0 && !vis[next.city][next.left_fuel]) {
                vis[next.city][next.left_fuel] = true;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int u, v, w;
    while(m--) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    int q, c, s, t;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &c, &s, &t);
        int time = bfs(c, s, t);
        if (time == -1) cout << "impossible" << endl;
        else cout << time << endl;
    }
}