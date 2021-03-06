// All Roads Lead to Rome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <tuple>
#include <string>
#include <unordered_map>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 200;

int n;

vector<vector<int>> map(MAX + 5, vector<int>(MAX + 5, INF));
vector<vector<int>> path;
unordered_map<string, int> string2id;
unordered_map<int, string> id2string;
vector<int> happy;

struct Node {
	int at;
	int happiness;
	int cost;
	int cities;
	vector<int> path;

	friend bool operator< (const Node & a, const Node &b) {
		if (a.cost != b.cost)
			return a.cost > b.cost;
		if (a.happiness != b.happiness)
			return a.happiness < b.happiness;
		return (1.0 * a.happiness / a.cities) < (1.0 * b.happiness / b.cities);
	}
};

tuple<int, int, int, int, vector<int>> dijkstra() {
	priority_queue<Node> q;
	vector<bool> visited(n, false);
	tuple<int, int, int, int, vector<int>> t;
	int res = 0;

	q.push({ 0, 0, 0, 1, vector<int>(1, 0) });
	while (!q.empty()) {
		Node cur = q.top(); q.pop();
		visited[cur.at] = true;

		if (0) {
			cout << id2string[cur.at] << " " << cur.cost << " " << cur.happiness << endl;
		}


		if (cur.at == string2id["ROM"]) {
			if (res == 0) {
				get<1>(t) = cur.cost;
				get<2>(t) = cur.happiness;
				get<3>(t) = cur.happiness / (cur.cities - 1);
				get<4>(t) = cur.path;
			}
			get<0>(t) = ++res;
		}

		for (int i = 0; i < n; i++) {
			if (map[cur.at][i] != INF && visited[i] == false) {
				vector<int> path = cur.path;
				path.push_back(i);
				q.push({ i, cur.happiness + happy[i], cur.cost + map[cur.at][i], cur.cities + 1, path });
			}
		}
	}

	return t;
}


int main() {
	int m, happiness;
	string city;

	cin >> n >> m >> city;

	happy.push_back(0);
	id2string[0] = city;
	string2id[city] = 0;
	path.resize(n);
	for (int i = 1; i < n; i++) {
		cin >> city >> happiness;
		string2id[city] = i;
		id2string[i] = city;
		happy.push_back(happiness);
	}
	for (int i = 0; i < m; i++) {
		string from, to;
		int cost;
		cin >> from >> to >> cost;
		map[string2id[from]][string2id[to]] = cost;
		map[string2id[to]][string2id[from]] = cost;
	}

	auto t = dijkstra();
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << endl;
	cout << id2string[get<4>(t)[0]];
	for (int i = 1; i < get<4>(t).size(); i++) {
		cout << "->" << id2string[get<4>(t)[i]];
	}
	cout << endl;
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
