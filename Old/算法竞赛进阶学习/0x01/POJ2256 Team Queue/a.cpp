#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <deque>
using namespace std;
const int N = 1e3 + 7;

map<string, int> mp;
deque<string> q[N];
vector<bool> flag(N, false);

int main() {
	int t, n, cnt = 1;
	string x;
	while (cin >> t, t) {
		mp.clear();
		for (int i = 0; i < N; i++) q[i].clear();

		for (int i = 1; i <= t; i++) {
			cin >> n;
			for (int j = 0; j < n; j++) {
				cin >> x;
				mp[x] = i;
			}
			flag[i] = false;
		}

		queue<deque<string>*> que;
		printf("Scenario #%d\n", cnt++);
		while (cin >> x, x != "STOP") {
			if (x == "ENQUEUE") {
				cin >> x;
				int idx = mp[x];
				if (!flag[idx]) flag[idx] = true, que.push(&q[idx]);
				q[idx].push_back(x);
			}
			else {
				deque<string> *item = que.front();
				cout << item->front() << endl;
				int idx = mp[item->front()];
				item->pop_front();
				if (item->empty()) flag[idx] = false, que.pop();
			}
		}
        cout << endl;
	}
}