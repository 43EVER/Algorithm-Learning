#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Event {
	int indegree, outdegree;
	int last;
	int earliest, latest;
};

struct Activity {
	int from, to, time;
	int last;
	int earliest, latest;
	int freetime;
};

struct Node {
	int from, to, flag;
};

bool cmp(const Node & a, const Node &b) {
	if (a.from != b.from)
		return a.from < b.from;
	return a.flag > b.flag;
}

struct Graph {
	vector<Event> vertexes;
	vector<Activity> edges;


	Graph(int n) {
		vertexes = vector<Event>(n, { 0, 0, -1, 0, 0 });
	}

	void AddEdge(int from, int to, int time) {
		edges.push_back({ from, to, time, vertexes[from].last, 0, 0x3f3f3f3f, 0 });
		vertexes[from].last = edges.size() - 1;

		vertexes[from].outdegree += 1;
		vertexes[to].indegree += 1;
	}

	vector<int> TopologicalOrder() {
		queue<int> q;
		vector<int> res;
		for (int i = 0; i < vertexes.size(); i++)
			if (vertexes[i].indegree == 0)
				q.push(i);

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			res.push_back(cur);

			int edge = vertexes[cur].last;
			while (edge != -1) {
				int to = edges[edge].to;
				vertexes[to].indegree -= 1;
				if (vertexes[to].indegree == 0) {
					q.push(to);
				}
				edge = edges[edge].last;
			}
		}

		return res;
	}

	bool CalEarliest() {
		queue<int> q;
		int cnt = 0;
		for (int i = 0; i < vertexes.size(); i++) {
			if (vertexes[i].indegree == 0) {
				vertexes[i].earliest = 0;
				q.push(i);
				cnt++;
			}
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			int edge = vertexes[cur].last;
			while (edge != -1) {
				int to = edges[edge].to;
				vertexes[to].indegree -= 1;
				vertexes[to].earliest = max(vertexes[to].earliest, vertexes[cur].earliest + edges[edge].time);
				if (vertexes[to].indegree == 0) {
					q.push(to);
					cnt++;
				}
				edge = edges[edge].last;
			}
		}

		if (cnt < vertexes.size())
			return false;
		return true;
	}

	void CalLatest() {
		int maxn = vertexes[0].earliest;
		for (int i = 1; i < vertexes.size(); i++) {
			if (vertexes[i].earliest > maxn)
				maxn = vertexes[i].earliest;
		}

		queue<int> q;

		for (int i = 0; i < vertexes.size(); i++) {
			vertexes[i].latest = maxn;
			if (vertexes[i].outdegree == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i = 0; i < edges.size(); i++) {
				int from = edges[i].from;
				int to = edges[i].to;
				if (to == cur) {
					//cout << cur << ": " << edges[i].from << " " << edges[i].to << endl;
					//cout << vertex[cur].earliest << " ";
					vertexes[from].outdegree -= 1;
					vertexes[from].latest = min(vertexes[from].latest, vertexes[to].latest - edges[i].time);
					if (vertexes[from].outdegree == 0)
						q.push(from);
					//cout << vertex[from].latest << endl;
				}
			}
		}
	}

	void CalActivity() {
		for (int i = 0; i < edges.size(); i++) {
			int from = edges[i].from;
			int to = edges[i].to;
			edges[i].freetime = vertexes[to].latest - vertexes[from].earliest - edges[i].time;
		}
	}

	void Out() {
		vector<Node> data;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i].freetime == 0) {
				data.push_back({ edges[i].from, edges[i].to, i });
			}
		}
		sort(data.begin(), data.end(), cmp);
		for (int i = 0; i < data.size(); i++) {
			cout << data[i].from + 1 << "->" << data[i].to + 1 << endl;
		}
	}

	void test() {
		cout << "--------------------------------" << endl;
		for (int i = 0; i < vertexes.size(); i++) {
			cout << i + 1 << ":" << vertexes[i].earliest << " " << vertexes[i].latest << endl;
		}
		cout << "--------------------------------" << endl;
		for (int i = 0; i < edges.size(); i++) {
			cout << i + 1 << ":" << edges[i].freetime << endl;
		}
	}
};


int main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		g.AddEdge(from - 1, to - 1, time);
	}

	//vector<int> res = g.TopologicalOrder();
	if (true == g.CalEarliest()) {
		int maxn = 0;
		for (int i = 0; i < g.vertexes.size(); i++)
			if (g.vertexes[i].earliest > maxn && g.vertexes[i].outdegree == 0)
				maxn = g.vertexes[i].earliest;
		cout << maxn << endl;
		g.CalLatest();
		g.CalActivity();
		g.Out();
	}
	else {
		cout << 0 << endl;
	}
}

