// Saving James Bond - Easy Version.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

struct Node {
	double x, y;
	int flag;
};
double jump;
vector<Node> crocodiles;
queue<Node> q;
bool visited[100 + 5];


bool judge(double x0, double y0, double x1, double y1, double jumpdis = jump) {
	return ((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) <= jumpdis * jumpdis;
}

void firstjump() {
	for (int i = 0; i < crocodiles.size(); i++) {
		if (judge(0, 0, crocodiles[i].x, crocodiles[i].y, jump + 7.5))
			q.push(crocodiles[i]);
	}
}

bool bfs() {
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		visited[cur.flag] = true;

		if (cur.x >= 50 - jump || cur.x <= -50 + jump)
			return true;
		else if (cur.y >= 50 - jump || cur.y <= -50 + jump)
			return true;
		else if (judge(cur.x, cur.y, 50, 50) || judge(cur.x, cur.y, 50, -50) ||
			judge(cur.x, cur.y, -50, 50) || judge(cur.x, cur.y, -50, -50))
			return true;

		for (int i = 0; i < crocodiles.size(); i++) {
			if (visited[i] == false && judge(cur.x, cur.y, crocodiles[i].x, crocodiles[i].y)) {
				q.push(crocodiles[i]);
			}
		}
	}
	return false;
}

int main() {
	int n;

	cin >> n >> jump;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		crocodiles.push_back({ x, y, i });
	}
	firstjump();
	cout << (bfs() ? "Yes" : "No") << endl;

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
