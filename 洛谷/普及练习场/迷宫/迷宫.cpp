// 迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <map>
#include <set>
using namespace std;

map<pair<int, int>, bool> maps;
set<pair<int, int> > s;

int mm[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int n, m, cnt = 0;
int fx, fy;

void dfs(int si, int sj) {
	if (si == fx && sj == fy) {
		cnt++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nexti = si + mm[i][0];
		int nextj = sj + mm[i][1];
		if (nexti <= 0 || nexti > n || nextj <= 0 || nextj > m || maps[{nexti, nextj}] || s.count({ nexti, nextj }))
			continue;
		maps[{nexti, nextj}] = true;
		dfs(nexti, nextj);
		maps[{nexti, nextj}] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, sx, sy;
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < t; i++) {
		int posi, posj;
		cin >> posi >> posj;
		s.insert({ posi, posj });
	}
	maps[{sx, sy}] = true;
	dfs(sx, sy);

	cout << cnt << endl;
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
