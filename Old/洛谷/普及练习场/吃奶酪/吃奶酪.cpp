
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cmath>
using namespace std;

pair<double, double> a[15];
double dis[15][15];
int n;
int lastpos;
double ans = 0x3f3f3f3f, cur;
bool b[15];

double getDis(int curpos) {
	return dis[lastpos][curpos];
}

void dfs(int pos) {
	if (pos == n) {
		ans = min(ans, cur);
		return;
	}
	if (cur >= ans)
		return;

	if (pos == 0) {
		for (int i = 0; i < n; i++) {
			b[i] = 1;
			cur = sqrt(pow(a[i].first, 2) + pow(a[i].second, 2));
			lastpos = i;
			dfs(pos + 1);
			cur = 0;
			b[i] = 0;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (b[i])
			continue;
		b[i] = 1;
		cur += getDis(i);
		int tmp = lastpos;
		lastpos = i;
		dfs(pos + 1);
		lastpos = tmp;
		cur -= getDis(i);
		b[i] = 0;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = sqrt(pow(a[i].first - a[j].first, 2) + pow(a[i].second - a[j].second, 2));

	dfs(0);

	cout << setprecision(2) << fixed << ans << endl;
}