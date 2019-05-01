// 单词方阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a[100 + 5], b[100 + 5];
string pattern = "yizhong";

int n;
int mm[][2] = { {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, -1}, {-1, 1} };

bool dfs(int si, int sj, int pos, int fx) {
	if (pos == 7)
		return true;
	int nexti = si + (6 - pos) * mm[fx][0];
	int nextj = sj + (6 - pos) * mm[fx][1];
	if (si < 0 || si > n || sj < 0 || sj > n || nexti < 0 || nexti >= n || nextj < 0 || nextj >= n || a[si][sj] != pattern[pos])
		return false;
	if (dfs(si + mm[fx][0], sj + mm[fx][1], pos + 1, fx)) {
		b[si][sj] = pattern[pos];
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	string tmp = a[0];
	for (int i = 0; i < tmp.size(); i++)
		tmp[i] = '*';
	for (int i = 0; i < n; i++)
		b[i] = tmp;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == 'y')
				for (int k = 0; k < 8; k++)
					dfs(i, j, 0, k);

	for (int i = 0; i < n; i++)
		cout << b[i] << endl;
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
