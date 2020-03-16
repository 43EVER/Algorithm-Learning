// 可达性统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
using namespace std;

const int MAX = 30000 + 5;

struct Edge {
	int u, v, w;
	int next;
} edge[MAX];
int cnt = 0;

struct Node {
	int indegree;
	int last;
} vtx[MAX];

bitset<MAX> size_[MAX];
int res[MAX];
int len = 0;
bool vis[MAX];
int n, m;

void addEdge(int u, int v, int w) {
	cnt++;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = vtx[u].last;
	vtx[u].last = cnt;
	vtx[v].indegree++;
}

void top_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (vtx[i].indegree == 0) q.push(i);
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res[len++] = cur;
		vis[cur] = true;
		for (int e = vtx[cur].last; e; e = edge[e].next) {
			int v = edge[e].v;
			if (vis[v]) continue;
			vtx[v].indegree--;
			if (!vtx[v].indegree) q.push(v);
		}
	}
}

int main() {
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		addEdge(u, v, 1);
	}

	top_sort();
	reverse(res, res + len);

	for (int i = 0; i < len; i++) {
		bitset<MAX> s;
		s[res[i]] = 1;
		for (int e = vtx[res[i]].last; e; e = edge[e].next)
			s |= size_[edge[e].v];
		size_[res[i]] = s;
	}

	for (int i = 1; i <= n; i++)
		cout << size_[i].count() << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
