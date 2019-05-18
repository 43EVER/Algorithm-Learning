#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>

int n;
std::stack<int> s;
int a[26], tot = 0, count = 0;

void dfs(int idx) {
    if (count >= 20) return;
    if (idx == n + 1 && tot == n) {
        ++count;
        for (int i = 0; i < tot; i++)
            std::cout << a[i];
        std::cout << std::endl;
        return;
    }
    if (s.size()) {
        int value = s.top(); s.pop();
        a[tot++] = value;
        dfs(idx);
        --tot;
        s.push(value);
    }
    if (idx <= n) {
        s.push(idx);
        dfs(idx + 1);
        s.pop();
    }
}

int main() {
    std::cin >> n;
    dfs(1);
}