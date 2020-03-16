#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;


struct Node {
	int l, r;
	ll min, max, sum;
	ll add;

	void update(ll value) {
		add += value;
		min += value;
		max += value;
		sum += (r - l + 1) * value;
	}

} t[N << 2];

pair<int, int> a[N];

inline int lc(ll p) {
	return p << 1;
}

inline int rc(ll p) {
	return p << 1 | 1;
}

inline void push_up(ll p) {
	t[p].max = max(t[lc(p)].max, t[rc(p)].max);
	t[p].min = min(t[lc(p)].min, t[rc(p)].min);
	t[p].sum = t[lc(p)].sum + t[rc(p)].sum;
}

inline void push_down(ll p) {
	if (t[p].add) {
		t[lc(p)].update(t[p].add);
		t[rc(p)].update(t[p].add);
		t[p].add = 0;
	}
}

void build_tree(int p, int l, int r) {
	t[p].l = l, t[p].r = r;
	if (l == r) {
		t[p].min = t[p].max = a[p].first;
		t[p].sum = a[l].second;
		return;
	}

	int mid = (l + r) >> 1;
	build_tree(lc(p), l, mid);
	build_tree(rc(p), mid + 1, r);
	push_up(p);
}

inline void update(int p, int l, int r, int value) {
	if (l <= t[p].l && t[p].r <= r) {
		t[p].update(value);
		return;
	}
	push_down(p);

	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) update(lc(p), l, r, value);
	if (r > mid) update(rc(p), l, r, value);

	push_up(p);
}

ll sum = 0, min_v = 0x3f3f3f3f, max_v = -0x3f3f3f3f;
void query(int p, int l, int r) {
	if (l <= t[p].l && t[p].r <= r) {
		sum += t[p].sum;
		min_v = min(min_v, t[p].min);
		max_v = max(max_v, t[p].max);
		return;
	}
	push_down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) query(lc(p), l, r);
	if (r > mid) query(rc(p), l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i].second;
	build_tree(1, 1, n);

	char op;
	int from, to;
	int value;

	for (int i = 0; i < q; i++) {
		cin >> op;
		if (op == 'Q') {
			sum = 0;
			cin >> from >> to;
			query(1, from, to);
			cout << sum << endl;
		} else {
			cin >> from >> to >> value;
			update(1, from, to, value);
		}
	}
}