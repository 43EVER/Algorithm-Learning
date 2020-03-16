// 离散化，二维前缀和，二分

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;
int c, n, cnt = 0, x, y;
int a[N], px[N], py[N], s[N][N];

void decrete() {
	sort(a + 1, a + cnt + 1);
	cnt = unique(a + 1, a + cnt + 1) - a - 1;
	for (int i = 0; i < n; i++) {
		x = lower_bound(a + 1, a + cnt + 1, px[i]) - a;
		y = lower_bound(a + 1, a + cnt + 1, py[i]) - a;
		++s[x][y];
	}

	for (int i = 1; i <= cnt; i++)
		for (int j = 1; j <= cnt; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
}

bool solve(int len) {
	int pos = upper_bound(a + 1, a + cnt + 1, a[cnt] - len + 1) - a;
	for (int i = 1; i <= pos; i++)
		for (int j = 1; j <= pos; j++) {
			x = upper_bound(a + 1, a + cnt + 1, a[i] + len - 1) - a - 1;
			y = upper_bound(a + 1, a + cnt + 1, a[j] + len - 1) - a - 1;
			if (s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1] >= c) return true;
		}
	return false;
}

int main() {
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		cin >> px[i] >> py[i];
		a[++cnt] = px[i], a[++cnt] = py[i];
	}

	decrete();
	int l = 1, r = a[cnt];
	while (l < r) {
		int m = (l + r) >> 1;
		if (solve(m)) r = m;
		else l = m + 1;
	}

	cout << l << endl;
}