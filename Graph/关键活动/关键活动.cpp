// 关键活动.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (const Node &a, const Node &b) {
		return a.earliest < b.earliest;
	}
};

struct Edge {
	int from, to, time;
	int last;
};

struct Node {
	int earliest, latest;
	int indegree;
	int last;

	friend bool operator== (const Node &a, const Node &b) {
		if (a.earliest == b.earliest && a.latest == b.latest &&
			a.indegree == b.indegree && a.last == b.last)
			return true;
		return false;
	}
};

struct Graph {
	vector<Node> vertex;
	vector<Edge> edges;

	Graph(int n) {
		vertex = vector<Node>(n, { 0, 0x3f3f3f3f, 0, -1 });
	}

	void AddEdge(int from, int to, int time) {
		edges.push_back({ from, to, time, vertex[from].last });
		vertex[from].last = edges.size() - 1;
		vertex[to].indegree += 1;
	}

	
	void Solve2() {
		vector<int> data(vertex.size());
		for (int i = 0; i < data.size(); i++)
			data[i] = i;
		for (Node & e : vertex) {
			int edge = e.last;
			while (edge != -1) {
				int to = edges[edge].to;
				if (e.latest > vertex[to].earliest - edges[edge].time) {
					e.latest = vertex[to].earliest - edges[edge].time;
					int flag = vertex.end() - find(vertex.begin(), vertex.end(), e) - 1;
					data[flag] = to;
				}
				edge = edges[edge].last;
			}
		}

		for (int i = 0; i < data.size(); i++) {
			if (vertex[i].earliest == vertex[i].last)
				cout << i + 1 << "->" << data[i] + 1 << endl;
		}
	}

	void Solve() {
		priority_queue<Node, vector<Node>, cmp> q;

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
	g.Solve();
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
