#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
const int N = 1e6 + 7;

std::stack<int> before, after;
int sum[N], max_sum[N];

int main() {
    int n, v, pos;
    char op;
    max_sum[0] = -0x3f3f3f3f;
    while (std::cin >> n) {
        before = std::stack<int>();
        after = std::stack<int>();
        while (n--) {
            scanf(" %c", &op);
            switch (op) {
            case 'I':
                scanf("%d", &v);
                before.push(v);
                pos = before.size();
                sum[pos] = v + sum[pos - 1];
                max_sum[pos] = std::max(max_sum[pos - 1], sum[pos]);
                break;
            case 'D':
                before.pop();
                break;
            case 'L':
                if (before.size()) {
                    after.push(before.top());
                    before.pop();
                }
                break;
            case 'R':
                if (after.size()) {
                    before.push(after.top());
                    after.pop();
                    pos = before.size();
                    sum[pos] = sum[pos - 1] + before.top();
                    max_sum[pos] = std::max(max_sum[pos - 1], sum[pos]);
                }
                break;
            case 'Q':
                scanf("%d", &v);
                printf("%d\n", max_sum[v]);
            }
        }
    }
}