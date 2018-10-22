// Emergency.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Edge {
	int from, to, dis;
	int last;
};

struct Node {
	int at, dis;
	
	friend bool operator< (const Node &a, const Node &b) {
		return a.dis > b.dis;
	}
};

class Graph {
private:
	vector<vector<int>> map;
	vector<bool> visited;
	vector<int> menArray;
	int destination;
	int minDis = 0x3f3f3f3f;
	int num, maxMen;

public:
	Graph(int n) {
		map = vector<vector<int>>(n, vector<int>(n, -1));
	}

	void addEdge(int from, int to, int dis) {
		map[from][to] = dis;
		map[to][from] = dis;
	}

	void addMan(int men) {
		menArray.push_back(men);
	}

	int bfs(int from, int to) {
		return -1;
	}

	pair<int, int> solve(int source, int destination) {
		minDis = 0x3f3f3f3f;
		num = 1;
		maxMen = 0;
		visited = vector<bool>(map.size(), false);
		this->destination = destination;

		dfs(source, 0, menArray[source]);

		return { num, maxMen };
	}

	void dfs(int at, int length, int men) {

		if (at == destination) {
			if (length > minDis) 
				return;
			
			if (length == minDis) {
				num++;
				maxMen = max(men, maxMen);
			}
			else {
				num = 1;
				maxMen = men;
				minDis = length;
			}
		}
		
		if (length > minDis)
			return;

		for (int i = 0; i < map.size(); i++) {
			if (visited[i] || map[at][i] == -1)
				continue;

			visited[i] = true;
			dfs(i, length + map[at][i], men + menArray[i]);
			visited[i] = false;
		}
	}
};

int main() {
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	Graph g(n);
	for (int i = 0; i < n; i++) {
		int men;
		cin >> men;
		g.addMan(men);
	}
	for (int i = 0; i < m; i++) {
		int from, to, dis;
		cin >> from >> to >> dis;
		g.addEdge(from, to, dis);
	}

	pair<int, int> res = g.solve(c1, c2);

	cout << res.first << " " << res.second << endl;

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
