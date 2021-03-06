// Forwards on Weibo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int map[1024][1024];

void solve1() {
	int n, maxlevel, tmp;
	memset(map, 0x3f, sizeof(map));
	cin >> n >> maxlevel;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		while (m--) {
			cin >> tmp;
			map[tmp][i] = 1;
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	int m;
	cin >> m;
	while (m--) {
		cin >> tmp;
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (tmp != i && map[tmp][i] >= 0 && map[tmp][i] <= maxlevel)
				res++;

		cout << res << endl;
	}
}

struct Edge {
	int u, v, w;
	int last;
};

class Graph {
private:
	vector<int> vertexes;
	vector<Edge> edges;

public:
	Graph(int n) {
		vertexes = vector<int>(n + 1, -1);
	}

	void addEdge(int u, int v, int w) {
		edges.push_back({ u, v, w, vertexes[u] });
		vertexes[u] = edges.size() - 1;
	}

	vector<int> dijsktra(int u) {
		vector<int> ndis(vertexes.size(), 0x3f3f3f3f);
		queue<int> q;
		q.push(u);
		q.push(0);
		ndis[u] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			int dis = q.front(); q.pop();

			int tmp = vertexes[cur];
			while (tmp != -1) {
				if (ndis[edges[tmp].v] == 0x3f3f3f3f) {
					q.push(edges[tmp].v);
					q.push(dis + 1);
					ndis[edges[tmp].v] = min(ndis[edges[tmp].v], dis + 1);
				}
				tmp = edges[tmp].last;
			}
		}
		return ndis;
	}
};

int main() {
	// solve1();
	int n, maxlevel;
	cin >> n >> maxlevel;
	Graph g(n);
	for (int i = 1; i <= n; i++) {
		int m, tmp;
		cin >> m;
		while (m--) {
			cin >> tmp;
			g.addEdge(tmp, i, 1);
		}
	}

	cin >> n;
	while (n--) {
		int tmp, res = 0;
		cin >> tmp;
		vector<int> ndis = g.dijsktra(tmp);
		for (int i = 1; i < ndis.size(); i++)
			if (ndis[i] != 0 && ndis[i] != 0x3f3f3f3f && ndis[i] <= maxlevel)
				res++;
		cout << res << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
