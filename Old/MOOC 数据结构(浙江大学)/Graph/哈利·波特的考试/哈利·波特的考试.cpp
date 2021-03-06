// 哈利·波特的考试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 0x3f3f3f3f;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		map[u][v] = w;
		map[v][u] = w;
	}

	for (int i = 1; i <= n; i++)
		map[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	int id = 0;
	int maxdis = INF;

	for (int i = 1; i <= n; i++) {
		int max = map[i][1];
		for (int j = 2; j <= n; j++)
			if (map[i][j] > max)
				max = map[i][j];
		if (max < maxdis) {
			id = i;
			maxdis = max;
		}
	}

	if (id == 0)
		cout << 0 << endl;
	else
		cout << id << " " << maxdis << endl;

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
