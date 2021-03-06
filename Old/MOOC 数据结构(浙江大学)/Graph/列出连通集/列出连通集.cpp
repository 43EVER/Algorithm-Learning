// 列出连通集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10;
int map[MAX + 5][MAX + 5];
int m, n;
vector<int> outdata;
bool visited[MAX + 5];

void dfs(int u) {
	outdata.push_back(u);
	visited[u] = true;
	for (int i = 0; i < m; i++) {
		if (visited[i] == false && map[u][i] == 1)
			dfs(i);
	}
}

void bfs(int u) {
	queue<int>	q;
	q.push(u);
	outdata.push_back(u);
	visited[u] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < m; i++) {
			if (visited[i] == false && map[cur][i] == 1) {
				q.push(i);
				outdata.push_back(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	memset(visited, false, sizeof(visited));
	memset(map, 0, sizeof(map));

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (visited[i] == false)
			dfs(i);
		if (outdata.size() > 0) {
			cout << "{ ";
			for (int j = 0; j < outdata.size(); j++)
				cout << outdata[j] << " ";
			cout << "}" << endl;
			outdata.clear();
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < m; i++) {
		if (visited[i] == false)
			bfs(i);
		if (outdata.size() > 0) {
			cout << "{ ";
			for (int j = 0; j < outdata.size(); j++)
				cout << outdata[j] << " ";
			cout << "}" << endl;
			outdata.clear();
		}
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
