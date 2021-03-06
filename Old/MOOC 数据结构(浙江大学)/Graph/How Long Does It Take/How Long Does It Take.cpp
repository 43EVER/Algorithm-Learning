// How Long Does It Take.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
	int from, to, time;
	int last;
};

struct Node {
	int last;
	int earliest;
	int indegree;
};

struct Graph {
	vector<Edge> edges;
	vector<Node> vertex;
	
	Graph(int n) {
		vertex = vector<Node>(n, { -1, 0, 0 });
	}

	void AddEdge(int from, int to, int time) {
		edges.push_back({ from, to, time, vertex[from].last });
		vertex[from].last = edges.size() - 1;
		vertex[to].indegree += 1;
	}

	void TopToStart() {
		queue<int> q;
		vector<bool> visited(vertex.size(), false);
		for (int i = 0; i < vertex.size(); i++) {
			if (vertex[i].indegree == 0) {
				q.push(i);
				vertex[i].earliest = 0;
			}
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			visited[cur] = true;
			int edge = vertex[cur].last;
			while (edge != -1) {
				int to = edges[edge].to;
				if (visited[to] == false) {
					vertex[to].indegree -= 1;
					vertex[to].earliest = max(vertex[to].earliest, vertex[cur].earliest + edges[edge].time);
					if (vertex[to].indegree == 0)
						q.push(to);
				}
				edge = edges[edge].last;
			}
		}

		bool flag = true;
		for (int i = 0; i < visited.size(); i++)
			if (visited[i] == false)
				flag = false;

		if (flag) {
			int maxn = -0x3f3f3f3f;
			for (int i = 0; i < vertex.size(); i++)
				if (vertex[i].earliest > maxn)
					maxn = vertex[i].earliest;

			cout << maxn << endl;
		}
		else
			cout << "Impossible" << endl;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		g.AddEdge(from, to, time);
	}
	g.TopToStart();
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
