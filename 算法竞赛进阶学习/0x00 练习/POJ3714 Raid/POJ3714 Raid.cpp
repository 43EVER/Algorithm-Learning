#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

const int N = 1e6 + 5;
const double INF = 1e300;

struct P {
	double x, y;
	bool flag;

	bool operator< (const P& b) const {
		return x < b.x;
	}
} p[N], q[N];

double dis(P a, P b) {
	if (a.flag == b.flag)
		return INF;
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double solve(int l, int r) {
	if (l == r) return INF;
	int m = (l + r) >> 1, tot = 0;
	double mx = p[m].x, d = min(solve(l, m), solve(m + 1, r));

	for (int i = l, j = m + 1; i <= m || j <= r; ++i) {
		while (j <= r && (p[i].y > p[j].y || i > m)) q[tot++] = p[j++];
		if (i <= m && abs(p[i].x - mx) < d) {
			for (int k = j - 1; k > m && j - k < 3; --k) d = min(d, dis(p[i], p[k]));
			for (int k = j; k <= r && k - j < 2; ++k) d = min(d, dis(p[i], p[k]));
		}
		if (i <= m) q[tot++] = p[i];
	}
	for (int i = 0; i < tot; i++) p[i + l] = q[i];

	return d;
}

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y), p[i].flag = false;
		for (int i = n; i < 2 * n; i++) scanf("%lf %lf", &p[i].x, &p[i].y), p[i].flag = true;
		sort(p, p + 2 * n);
		cout << fixed << setprecision(3) << solve(0, 2 * n - 1) << endl;
	}
}