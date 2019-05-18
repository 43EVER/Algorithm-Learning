#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const int N = 1e6 + 7;

int a[N], n;

int lowbit(int x) {
    return x & (-x);
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(int x, int v) {
    while (x <= n) {
        a[x] += v;
        x += lowbit(x);
    }
}

int main() {
    int x;
    while (std::cin >> n) {
        for (int i = 1; i <= n; i++) {
            std::cin >> x;
            add(i, x);
        }

        while (std::cin >> x) {
            std::cout << query(x) << std::endl;
        }
    }
    return 0;
}