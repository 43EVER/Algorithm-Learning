// 公路村村通.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
	int from, to;
	int price;
};

struct cmp {
	bool operator() (const Edge & a, const Edge & b) {
		return a.price > b.price;
	}
};

vector<int> bcj;

int find(int a) {
	return bcj[a] == a ? a : (bcj[a] = find(bcj[a]));
}

void combin(int a, int b) {
	bcj[find(a)] = bcj[find(b)];
}

//kruskal
void solve1() {
	int n, m;
	priority_queue<Edge, vector<Edge>, cmp> q;

	cin >> n >> m;
	for (int i = 0; i < n + 1; i++)
		bcj.push_back(i);
	for (int i = 0; i < m; i++) {
		int from, to, price;
		cin >> from >> to >> price;
		q.push({ from, to, price });
		q.push({ to, from, price });
	}

	int ans = 0;
	while (!q.empty()) {
		Edge top = q.top(); q.pop();
		if (find(top.from) != find(top.to)) {
			combin(top.from, top.to);
			ans += top.price;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
		if (bcj[i] == i) res++;

	if (res == 1)
		cout << ans << endl;
	else
		cout << -1 << endl;
}

//prim
void solve2() {
	int n, m;
	vector<Edge> edges;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, price;
		cin >> from >> to >> price;
		edges.push_back({ from - 1, to - 1, price });
		edges.push_back({ to - 1, from - 1, price });
	}
	vector<bool> visited(n, false);
	visited[0] = true;
	priority_queue < Edge, vector<Edge>, cmp> t;
	for (int i = 0; i < edges.size(); i++)
		if (edges[i].from == 0)
			t.push(edges[i]);

	int res = 0;
	while (!t.empty()) {
		Edge cur = t.top(); t.pop();
		if (visited[cur.to] == false) {
			visited[cur.to] = true;
			res += cur.price;
			for (int i = 0; i < edges.size(); i++)
				if (edges[i].from == cur.to)
					t.push(edges[i]);
		}
	}

	int flag = 0;
	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			flag = 1;

	cout << (flag == 0 ? res : -1) << endl;
}

int main() {
	solve2();
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
