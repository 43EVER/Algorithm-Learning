#include <iostream>
#include <algorithm>
using namespace std;

int a[20];
int use = 0;
int car[20];
int n, w;
int ans = 0x3f3f3f3f;

void dfs(int cur) {
    if (use >= ans) return;
    if (cur == n) {
        ans = use;
        return;
    }
    for (int i = 0; i < use; i++) {
        if (car[i] + a[cur] <= w) {
            car[i] += a[cur];
            dfs(cur + 1);
            car[i] -= a[cur];
        }
    }
    car[use++] = a[cur];
    dfs(cur + 1);
    use--;
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, [](int a, int b) {return a > b;});
    dfs(0);

    cout << ans << endl;
}