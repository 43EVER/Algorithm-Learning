// 单词接龙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <string>
using namespace std;

int n, maxLen, used[30 + 5];
string datas[30 + 5];
int minLen[30 + 5][30 + 5];

int getMinLen(int a, int b) {
	if (minLen[a][b] != -1)
		return minLen[a][b];
	int res = 0;
	for (int len = 1; len < datas[a].length(); len++) {
		int i = datas[a].length() - len;
		int j = 0;
		while (i < datas[a].length() && j < datas[b].length()) {
			if (datas[a][i] == datas[b][j])
				i++, j++;
			else
				break;
		}
		if (i == datas[a].length() && j < datas[b].length()) {
			res = len;
			break;
		}
	}
	minLen[a][b] = res;
	return minLen[a][b];
}

void dfs(int last, int len) {
	maxLen = max(maxLen, len);
	for (int i = 0; i < n; i++) {
		if (used[i] < 2 && getMinLen(last, i)) {
			used[i]++;
			dfs(i, len + datas[i].length() - getMinLen(last, i));
			used[i]--;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> datas[i];
		for (int j = 0; j < n; j++)
			minLen[i][j] = -1;
	}
	char start;
	cin >> start;

	for (int i = 0; i < n; i++) {
		if (datas[i][0] == start) {
			used[i]++;
			dfs(i, datas[i].length());
			used[i]--;
		}
	}

	cout << maxLen << endl;
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
