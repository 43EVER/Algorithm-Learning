#include <cstdio>
#include <iostream>
using namespace std;

int a[1000090], b[1000090];
int ans = 0, m, n, x, pos, zero;

void msort(int l, int r) {
	if (l == r) return;
	int m = (l + r) >> 1;
	msort(l, m);
	msort(m + 1, r);
	int i = l, j = m + 1;
	for (int k = l; k <= r; k++)
		if (j > r || i <= m && a[i] <= a[j]) b[k] = a[i++];
		else ans += m - i + 1, b[k] = a[j++];
	for (int k = l; k <= r; k++) a[k] = b[k];
}

int main() {
	while (cin >> m >> n && m && n) {
		for (int i = 0; i < m * n; i++) {
			scanf("%d", &a[pos++]);
			if (!a[pos - 1]) --pos, zero = m - i / n - 1;
		}
		msort(0, m * n - 2);
		if (n & 1) zero = 0;
		if ((zero + ans) % 2 == 0)
			printf("YES\n");
		else
			printf("NO\n");
		ans = 0, pos = 0, zero = 0;
	}
}