#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

struct Node {
    long long height;
    int width;
};

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        long long ans = 0, x;
        std::stack<Node> s;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            if (s.empty() || x > s.top().height) {
                s.push({x, 1});
            } else {
                int width = 0;
                while (s.size() && x < s.top().height) {
                    width += s.top().width;
                    ans = std::max(ans, width * s.top().height);
                    s.pop();
                }
                s.push({x, width + 1});
            }
        }
        int width = 0;
        while (s.size() && 0 < s.top().height) {
            width += s.top().width;
            ans = std::max(ans, width * s.top().height);
            s.pop();
        }
        printf("%lld\n", ans);
    }
}