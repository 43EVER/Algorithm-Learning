#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 80;

int a[N], v[N];
int cnt, len, x;

bool dfs(int stick, int cab, int last) {
    if (stick > cnt) return true;
    if (cab == len) return dfs(stick + 1, 0, 1);

    int fail = 0;
    for (int i = last; i < x; i++)
        if (!v[i] && a[i] != fail && cab + a[i] <= len) {
            v[i] = 1;
            if (dfs(stick, cab + a[i], i)) return true;
            fail = a[i];
            v[i] = 0;
            if (cab == 0 || cab + a[i] == len) return false;
        }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        int sum = 0, val = 0;
        x = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[x];
            if (a[x] > 50) continue;
            sum += a[x];
            val = max(val, a[x]);
            x++;
        }
        sort(a + 1, a + x, [](int a, int b) {return a > b;});
        for (len = val; len <= sum; len++) {
            if (sum % len != 0) continue;
            cnt = sum / len;
            memset(v, 0, sizeof(v));
            if (dfs(1, 0, 1)) break;
        }
        cout << len << endl;
    }
}