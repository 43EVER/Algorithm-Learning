// Dijkstra.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1000;

struct Node {
	int at;
	int dis;
	friend bool operator< (const Node &a, const Node &b) {
		return a.dis > b.dis;
	}
};


pair<vector<int>, vector<int>> Dijkstra(vector<vector<int>>map, int s) {
	vector<bool> visited(map.size(), false);
	vector<int> dis(map.size(), 0x3f3f3f3f);
	vector<int> path(map.size(), -1);
	priority_queue<Node> q;
	q.push({ s, 0 });
	visited[s] = true;

	while (!q.empty()) {
		Node cur = q.top(); q.pop();
		dis[cur.at] = cur.dis;
		for (int i = 1; i < map.size(); i++) {
			if (map[cur.at][i] != 0x3f3f3f3f && visited[i] == false) {
				q.push({ i, cur.dis + map[cur.at][i] });
				visited[i] = true;
				path[i] = cur.at;
			}
		}
	}

	return { dis, path };
}

pair<vector<vector<int>>, vector<vector<int>>> Floyd(vector<vector<int>>map) {
	vector<vector<int>>dis(map.size(), vector<int>(map.size(), 0x3f3f3f3f));
	vector<vector<int>>path(map.size(), vector<int>(map.size(), - 1));

	for (int i = 1; i < map.size(); i++)
		for (int j = 1; j < map.size(); j++)
			dis[i][j] = map[i][j];

	for (int k = 1; k < map.size(); k++)
		for (int i = 1; i < map.size(); i++)
			for (int j = 1; j < map.size(); j++)
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = k;
				}

	return { dis, path };
}

int main()
{
	vector< vector<int> >map(11, vector<int>(11, 0x3f3f3f3f));
	map[1][2] = 5;
	map[1][3] = 3;
	map[1][4] = 2;
	map[3][4] = 1;
	map[4][5] = 1;
	map[5][3] = 1;

	//pair<vector<int>, vector<int>> data = Dijkstra(map, 1);
	//for (int i = 1; i < map.size(); i++)
	//	cout << data.first[i] << " ";
	//cout << endl;
	//for (int i = 1; i < map.size(); i++)
	//	cout << data.second[i] << " ";
	auto data = Floyd(map);
	for (int i = 1; i < map.size(); i++) {
		for (int j = 1; j < map.size(); j++)
			cout << data.first[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i < map.size(); i++) {
		for (int j = 1; j < map.size(); j++)
			cout << data.second[i][j] << " ";
		cout << endl;
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
