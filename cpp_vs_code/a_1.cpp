#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t, a[100];
    cin >> t;
    while (t--) {
        int n, key;
        cin >> n >> key;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        int pos = find(a + 1, a + n + 1, key) - a;
        if (pos == n) pos = -1;
        cout << pos << endl;
    }
}