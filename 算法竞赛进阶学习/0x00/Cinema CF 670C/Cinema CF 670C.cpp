#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;
int a[N], b[N << 2], num[N << 2];
struct {
	int audio, subtitles;
} p[N];

int len;

int query(int x) {
	return lower_bound(b + 1, b + 1 + len, x) - b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, tot = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], b[++tot] = a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> p[i].audio, b[++tot] = p[i].audio;
	for (int i = 0; i < m; i++) cin >> p[i].subtitles, b[++tot] = p[i].subtitles;

	sort(b + 1, b + 1 + tot);
	len = unique(b + 1, b + 1 + tot) - b - 1;
	for (int i = 0; i < n; i++)
		num[query(a[i])]++;
	int ansi = 1, ansa = -1, anss = -1;
	for (int i = 0; i < m; i++) {
		int cnt1 = num[query(p[i].audio)], cnt2 = num[query(p[i].subtitles)];
		if (cnt1 > ansa) ansi = i + 1, ansa = cnt1, anss = cnt2;
		else if (cnt1 == ansa && cnt2 > anss) ansi = i + 1, anss = cnt2;
	}
	cout << ansi << endl;
}