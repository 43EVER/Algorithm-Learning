// [SHOI2002]滑雪.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int a[100 + 5][100 + 5];
int ans[100 + 5][100 + 5];
int mm[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int n, m;

int dfs(int si, int sj) {
	if (ans[si][sj])
		return ans[si][sj];
	ans[si][sj] = 1;
	for (int i = 0; i < 4; i++) {
		int ni = si + mm[i][0];
		int nj = sj + mm[i][1];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || a[si][sj] <= a[ni][nj])
			continue;
		ans[si][sj] = max(ans[si][sj], 1 + dfs(ni, nj));
	}
	return ans[si][sj];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int maxx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			maxx = max(dfs(i, j), maxx);

	cout << maxx << endl;
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
