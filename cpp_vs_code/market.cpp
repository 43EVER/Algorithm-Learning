#include <iostream>
#include <algorithm>
using namespace std;

const int N = 305;
const int INF = 0x3f3f3f3f;
const int M = 1e6 + 5;

long long int f[M], ans[M];
long long int tot;

struct {
    int c, v, t;
} a[N];

struct {
    int t, m, id;
} b[N];

inline void dp (int val, int c) {
    for (int i = tot; i >= val; i--) f[i] = min(f[i], f[i - val]  + c);
    for (int i = tot - 1; i > 0; i--) f[i] = min(f[i], f[i + 1]);
}

inline int search(int c) {
    int l = 0, r = tot, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (f[mid] <= c) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].c >> a[i].v >> a[i].t, tot += a[i].v;
    for (int i = 1; i <= m; i++)
        cin >> b[i].t >> b[i].m, b[i].id = i;
    
    sort(a + 1, a + 1 + n, [](auto a, auto b) {
        return a.t < b.t;
    });
    sort(b + 1, b + 1 + m, [](auto a, auto b) {
        return a.t < b.t;
    });

    for (int i = 1; i <= tot; i++) f[i] = INF;
    for (int i = 1, j = 1; i <= m; i++) {
        while (j <= n && a[j].t <= b[i].t) dp(a[j].v, a[j].c), j++;
        ans[b[i].id] = search(b[i].m);
    }
    
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;

    return 0;
}