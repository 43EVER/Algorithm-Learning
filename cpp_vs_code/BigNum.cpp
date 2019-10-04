#include <iostream>
#include <string>
using namespace std;

typedef long long LL;

inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main() {
    string num;
    cin >> num;

    int p;
    cin >> p;

    LL ans = 0;
    for (int i = 0; i < num.length(); i++)
        ans = (ans * 10 + num[i] - '0') % p;

    cout << ans << endl;
}