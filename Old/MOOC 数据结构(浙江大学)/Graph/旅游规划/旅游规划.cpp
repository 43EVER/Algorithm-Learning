// 旅游规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct Node {
	int at, dis, price;

	friend bool operator< (const Node & a, const Node & b) {
		if (a.dis == b.dis)
			return a.price > b.price;
		return a.dis > b.dis;
	}
};

struct Edge {
	int from, to;
	int price;
	int price;
	int last;
};

class Graph {
private:
	vector<Edge> edges;
	vector<int> vertex;

public:
	Graph(int n) {
		vertex = vector<int>(n, -1);
	}

	void addEdge(int from, int to, int dis, int price) {
		edges.push_back({ from, to, dis, price, vertex[from] });
		vertex[from] = edges.size() - 1;
	}

	pair<int, int> solve(int from, int to) {
		priority_queue<Node> q;
		vector<bool> visited(vertex.size(), false);
		q.push({ from, 0, 0 });
		while (!q.empty()) {
			Node cur = q.top(); q.pop();
			int edge = vertex[cur.at];

			//cout << cur.at << " " << cur.dis << " " << cur.price << endl;
			visited[cur.at] = true;

			if (cur.at == to) {
				return { cur.dis, cur.price };
			}

			while (edge != -1) {
				if (visited[edges[edge].to] == false) {
					//cout << "push " << edges[edge].to << " " << edges[edge].dis << " " << edges[edge].price << endl;
					q.push({ edges[edge].to, edges[edge].price + cur.dis, edges[edge].price + cur.price });
				}
				edge = edges[edge].last;
			}
		}
		return { -1, -1 };
	}
};

int main() {
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	Graph g(n);
	while (m--) {
		int from, to, dis, price;
		cin >> from >> to >> dis >> price;
		g.addEdge(from, to, dis, price);
		g.addEdge(to, from, dis, price);
	}

	pair<int, int> ans = g.solve(s, d);
	cout << ans.first << " " << ans.second << endl;

	return 0;
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
