#include <iostream>
using namespace std;

typedef unsigned long long LL;

const unsigned long long MOD = 1e9 + 7;

LL pow(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

int main() {
    LL len, k;
    cin >> len >> k;
    cout << (len * pow(pow(2, k, MOD), MOD - 2, MOD) ) % MOD << endl;
}