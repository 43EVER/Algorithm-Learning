#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;

int a[N], f[N][20];
int n;

void ST_prework() {
	for (int i = 1; i <= n; i++) f[i][0] = a[i];
	int t = log2(n) + 1;
	for (int j = 1; j < t; j++)
		for (int i = 1; i <= n - (1 << j) + 1; i++)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int ST_query(int i, int j) {
	int k = log2(j - i + 1);
	return max(f[i][k], f[j - (1 << k) + 1][k]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ST_prework();
	int l, r;
	while (cin >> l >> r)
		cout << ST_query(l, r) << endl;
}