#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1e5 + 7;
int ans[N], dt[N];

int main() {
	int n, m, q, u, v, t, x;
	cin >> n >> m >> q >> u >> v >> t;

	if (u == 0) {
		priority_queue<int> que;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			que.push(x);
		}
		for (int i = 0; i < m; i++) {
			u = que.top(); que.pop();
			que.push(u); que.push(0);
			cout << u << " ";
		}
		cout << endl;
		while (que.size())
			cout << que.top() << " ", que.pop();
		cout << endl;

	} else {
		double p = 1.0 * u / v;
		int offset = 0, tmp1, tmp2, tmp3, count = 1;
		queue<int> a, b, c;
		
		for (int i = 0; i < n; i++) scanf("%d", &dt[i]);
		sort(dt, dt + n, [](int a, int b) {return b < a;});
		for (int i = 0; i < n; i++) a.push(dt[i]);
		
		for (int i = 0; i < m; i++) {
			tmp1 = tmp2 = tmp3 = -0x3f3f3f3f;
			if (a.size()) tmp1 = a.front();
			if (b.size()) tmp2 = b.front();
			if (c.size()) tmp3 = c.front();
			if (tmp1 >= tmp2 && tmp1 >= tmp3) u = tmp1, a.pop();
			else if (tmp2 >= tmp1 && tmp2 >= tmp3) u = tmp2, b.pop();
			else u = tmp3, c.pop();

			u += offset;
			if (count % t == 0) cout << u << " ";
			b.push(floor(u * p) - q - offset);
			c.push(u - floor(u * p) - q - offset);
			offset += q;
			count++;
		}
		cout << endl;
		
		count = 1;
		while (a.size() || b.size() || c.size()) {
			tmp1 = tmp2 = tmp3 = -0x3f3f3f3f;
			if (a.size()) tmp1 = a.front();
			if (b.size()) tmp2 = b.front();
			if (c.size()) tmp3 = c.front();

			if (tmp1 >= tmp2 && tmp1 >= tmp3) u = tmp1, a.pop();
			else if (tmp2 >= tmp1 && tmp2 >= tmp3) u = tmp2, b.pop();
			else u = tmp3, c.pop();
			
			if (count % t == 0) cout << u + offset << " ";
			count++;
		}
		cout << endl;

	}
}