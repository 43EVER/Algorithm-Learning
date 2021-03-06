// 六度空间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct Node {
	int v;
	int depth;
	int last;
};

vector<Node> edges;
vector<int> vertex;

void addedge(int u, int v) {
	edges.push_back({ v, 0, vertex[u] });
	vertex[u] = edges.size() - 1;
	edges.push_back({ u, 0, vertex[v] });
	vertex[v] = edges.size() - 1;
}

int bfs(int u) {
	int s = 0;
	vector<bool>visited(vertex.size(), false);
	queue<int> q;
	q.push(u);
	q.push(0);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int dis = q.front(); q.pop();

		if (dis <= 6)
			s++;

		int tmp = vertex[cur];
		while (tmp != -1) {
			if (visited[edges[tmp].v] == false) {
				q.push(edges[tmp].v);
				q.push(dis + 1);
				visited[edges[tmp].v] = true;
			}
			tmp = edges[tmp].last;
		}
	}

	return s - 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	vertex = vector<int>(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		int connected = bfs(i);
		cout << i << ": " << fixed << setprecision(2) << 100.0 * connected / n << "%" << endl;
	}

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
