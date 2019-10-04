#include <iostream>
using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

LL pow(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL ans = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ans;
}

int main() {
    LL len, k;
    cin >> len >> k;
    cout << (len * pow(pow(2, k, MOD), MOD - 2, MOD) ) % (MOD) << endl;
}