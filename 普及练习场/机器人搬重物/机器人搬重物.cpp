#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int i, j, cnt, fx;
	friend bool operator< (const Node& a, const Node& b) {
		return b.cnt < a.cnt;
	}
};

const int N = 55;
const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
int n, m, mp[N][N], si, ei, sj, ej;
bool vis[N][N][4];
char fx;

int bfs() {
	if (mp[si][sj])
		return -1;
	int _fx = 0;
	switch (fx) {
		case 'E': _fx = 0; break;
		case 'S': _fx = 1; break;
		case 'W': _fx = 2; break;
		case 'N': _fx = 3; break;
	}
	Node fir = { si, sj, 0, _fx };
	vis[si][sj][_fx] = 1;
	priority_queue<Node> q;
	q.push(fir);
	while (!q.empty()) {
		Node now = q.top(), next; q.pop();
		if (now.i == ei && now.j == ej)
			return now.cnt;
		for (int i = 1; i <= 3; i++) {
			next = { now.i + i * dx[now.fx], now.j + i * dy[now.fx], now.cnt + 1, now.fx };
			if (next.i <= 0 || next.i >= n || next.j <= 0 || next.j >= m || mp[next.i][next.j]) break;
			else if (!vis[next.i][next.j][next.fx])
				q.push(next), vis[next.i][next.j][next.fx] = 1;
		}
		next = { now.i, now.j, now.cnt + 1, (now.fx + 1) % 4 };
		if (!vis[next.i][next.j][next.fx])
			q.push(next), vis[next.i][next.j][next.fx] = 1;
		next = { now.i, now.j, now.cnt + 1, (now.fx + 3) % 4 };
		if (!vis[next.i][next.j][next.fx])
			q.push(next);
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1)
				mp[i - 1][j] = mp[i][j - 1] = mp[i - 1][j - 1] = 1;
		}
	
	cin >> si >> sj >> ei >> ej >> fx;
	cout << bfs();
}