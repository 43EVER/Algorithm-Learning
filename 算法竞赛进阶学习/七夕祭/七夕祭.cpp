#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

long long rows[N], cols[N], s[N];
long long _size;

long long myabs(long long a) {
	return a < 0 ? -a : a;
}

long long f(long long* a, int len) {
	s[0] = 0;
	for (int i = 1; i <= len; i++)
		s[i] = s[i - 1] + a[i] - _size;
	sort(s + 1, s + 1 + len);
	int pos = (len + 1) >> 1;
	long long ans = 0;
	for (int i = 1; i <= len; i++)
		ans += myabs(s[i] - s[pos]);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, t, row, col;
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++)
		cin >> row >> col, rows[row]++, cols[col]++;

	bool can_row = false, can_col = false;
	long long ans = 0;
	if (t % n == 0) {
		can_row = true;
		_size = t / n;
		ans += f(rows, n);
	}
	if (t % m == 0) {
		can_col = true;
		_size = t / m;
		ans += f(cols, m);
	}

	if (can_row && can_col)
		cout << "both ";
	else if (can_row)
		cout << "row ";
	else if (can_col)
		cout << "column ";
	else
		cout << "impossible ";
	if (ans)
		cout << ans;
}