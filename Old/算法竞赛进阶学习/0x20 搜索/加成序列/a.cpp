#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100 + 100;

int max_dep = 1;
bool v[N];
int a[N];
int n;

bool dfs(int dep) {
    if (dep > max_dep) {
        if (a[max_dep] == n) return true;
        return false;
    }

    for (int i = dep - 1; i >= 1; i--)
        for (int j = i; j >= 1; j--) {
            a[dep] = a[i] + a[j];
            if (a[dep] <= n && a[dep] > a[dep - 1] && !v[a[dep]]) {
                v[a[dep]] = true;
                if (dfs(dep + 1)) return true;
                v[a[dep]] = false;
            }
        }
    return false;
}

int main() {
    while (cin >> n && n) {
        a[1] = 1;
        max_dep = 1;
        while (!dfs(2)) {
            max_dep++;
            memset(v, false, sizeof(v));
        }
        for (int i = 1; i <= max_dep; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}