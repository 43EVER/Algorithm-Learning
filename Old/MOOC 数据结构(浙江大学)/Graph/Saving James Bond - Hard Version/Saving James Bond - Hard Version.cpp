// Saving James Bond - Hard Version.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;


struct Point {
	int x, y;
	int flag;
};

vector<int>path;
queue<int> q;
vector<bool>visited;
vector<Point>point;

bool cmp(const Point &a, const Point &b) {
	return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
}

bool judge(double x0, double y0, double x1, double y1, double jump) {
	if (pow(x0 - x1, 2) + pow(y0 - y1, 2) <= pow(jump, 2))
		return true;
	else
		return false;
}

void firstjump(double jumpdis) {
	vector<Point> tmp;
	for (int i = 0; i < point.size(); i++) {
		if (judge(0, 0, point[i].x, point[i].y, jumpdis + 7.5)) {
			tmp.push_back(point[i]);
			visited[i] = true;
		}
	}
	sort(tmp.begin(), tmp.end(), cmp);
	for (int i = 0; i < tmp.size(); i++) {
		q.push(tmp[i].flag); q.push(1); q.push(-1);
	}
}

int bfs(double jumpdis) {
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int dis = q.front(); q.pop();
		int last = q.front(); q.pop();
		path[cur] = last;

		if (point[cur].x >= 50 - jumpdis || point[cur].x <= -50 + jumpdis)
			return cur;
		else if (point[cur].y >= 50 - jumpdis || point[cur].y <= -50 + jumpdis)
			return cur;
		else if (judge(point[cur].x, point[cur].y, 50, 50, jumpdis) || judge(point[cur].x, point[cur].y, 50, -50, jumpdis) ||
			judge(point[cur].x, point[cur].y, -50, 50, jumpdis) || judge(point[cur].x, point[cur].y, -50, -50, jumpdis))
			return cur;

		for (int i = 0; i < point.size(); i++) {
			if (visited[i] == false && judge(point[cur].x, point[cur].y, point[i].x, point[i].y, jumpdis)) {
				q.push(i);
				q.push(dis + 1);
				q.push(cur);
				visited[i] = true;
			}
		}
	}

	return -1;
}


int main() {
	int n, d;
	cin >> n >> d;
	path = vector<int>(n, -1);
	visited = vector<bool>(n, false);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		point.push_back({ x, y, i });
	}

	firstjump(d);
	int res = bfs(d);
	if (d >= 50) {
		cout << 1 << endl;
	}
	else if (res != -1) {
		stack<int> s;
		int dist = 1;

		while (res != -1) {
			dist++;
			s.push(res);
			res = path[res];
		}

		cout << dist << endl;
		while (!s.empty()) {
			int tmp = s.top(); s.pop();
			cout << point[tmp].x << " " << point[tmp].y << endl;
		}
	}
	else
		cout << 0 << endl;
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
