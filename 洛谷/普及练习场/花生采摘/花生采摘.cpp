// 花生采摘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <functional>
#include <tuple>
using namespace std;

int f(int si, int sj, int ei, int ej) {
	return abs(si - ei) + abs(sj - ej);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, k;
	cin >> m >> n >> k;
	vector< vector<int> > maps(m, vector<int>(n));
	using Node = pair<int, int>;
	auto cmp = [&](Node a, Node b) {
		return maps[b.first][b.second] < maps[a.first][a.second];
	};
	set<Node, decltype(cmp)> s(cmp);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] != 0)
				s.insert({ i, j });
		}

	auto it = s.begin();
	int ans = 0;

	int ati = it->first;
	int atj = it->second;
	k -= ati + 2;
	if (k > ati) {
		ans += maps[ati][atj];
		it++;
	}

	while (it != s.end()) {
		int dis = f(ati, atj, it->first, it->second);
		k -= dis + 1;
		if (k > it->first) {
			ati = it->first;
			atj = it->second;
			ans += maps[it->first][it->second];
			it++;
		}
		else {
			break;
		}
	}
	cout << ans << endl;
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
