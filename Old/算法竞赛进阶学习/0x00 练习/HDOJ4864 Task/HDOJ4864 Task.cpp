// 两个值的贪心，对货物（价值从大到小），每次把时间符合的都选出来，然后选个最便宜的机子
// 为什么不直接在set里找，因为在set里找的，只能保证
// 1、时间大于需要的，level不一定符合
// 2、时间等于需要的时候，level大于等于需要的

#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

struct Node {
	long long time, level;

	friend bool operator< (const Node& a, const Node& b) {
		return a.level < b.level;
	}
} a[100010], b[100010];

bool cmp(const Node& a, const Node& b) {
	int tmp1 = a.time * 500 + a.level * 2;
	int tmp2 = b.time * 500 + b.level * 2;
	return tmp1 < tmp2;
}

bool cmp2(const Node& a, const Node& b) {
	return a.time < b.time;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> a[i].time >> a[i].level;
		for (int i = 0; i < m; i++) cin >> b[i].time >> b[i].level;

		sort(a, a + n, cmp), sort(b, b + m, cmp);
		int cnt = 0, lastpos = n;
		long long money = 0;
		multiset<Node> s;

		for (int i = m - 1; i >= 0; i--) {
			int pos = lower_bound(a, a + n, b[i], cmp2) - a;
			if (pos == n) continue;
			for (int j = pos; j < lastpos; j++) s.insert(a[j]);
			lastpos = pos;
			auto it = s.lower_bound(b[i]);
			if (it == s.end()) continue;
			++cnt, money += b[i].time * 500 + b[i].level * 2;
			s.erase(it);
		}

		cout << cnt << " " << money << endl;
	}
}