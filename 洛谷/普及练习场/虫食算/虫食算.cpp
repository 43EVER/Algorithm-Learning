// 虫食算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 30;

vector<bool> used(maxn);
vector<string> s(3);
vector<int> ans(maxn, -1);
int n;

int getData(int si, int sj) {
	return ans[s[si][sj] - 'A'];
}

void setData(int si, int sj, int data) {
	ans[s[si][sj] - 'A'] = data;
}

void dfs(int rowpos, int colpos, int jinwei) {
	if (colpos < 0)
		if (!jinwei) {
			for (int i = 0; i < n - 1; i++)
				cout << ans[i] << " ";
			cout << ans[n - 1];
			exit(0);
		}
		else {
			return;
		}

	for (int j = colpos - 1; j >= 0; j--) {
		int w1 = getData(0, j);
		int w2 = getData(1, j);
		int w3 = getData(2, j);
		if (w1 == -1 || w2 == -1 || w3 == -1)
			continue;
		if ((w1 + w2) % n != w3 && (w1 + w2 + 1) % n != w3)
			return;
	}

	if (getData(rowpos, colpos) == -1)
		for (int value = n - 1; value >= 0; value--)
			if (!used[value])
				if (rowpos < 2) {
					used[value] = true;
					setData(rowpos, colpos, value);
					dfs(rowpos + 1, colpos, jinwei);
					used[value] = false;
					setData(rowpos, colpos, -1);
				}
				else {
					int w = getData(0, colpos) + getData(1, colpos) + jinwei;
					if (w % n != value)
						continue;
					used[value] = true;
					setData(rowpos, colpos, value);
					dfs(0, colpos - 1, w / n);
					used[value] = false;
					setData(rowpos, colpos, -1);
				}
	
	if (getData(rowpos, colpos) != -1)
		if (rowpos < 2) {
			dfs(rowpos + 1, colpos, jinwei);
		}
		else {
			int w = getData(0, colpos) + getData(1, colpos) + jinwei;
			if (w % n != getData(rowpos, colpos))
				return;
			dfs(0, colpos - 1, w / n);
		}
}

int main() {
	cin >> n;
	for (int i = 0; i < 3; i++)
		cin >> s[i];
	dfs(0, n - 1, 0);
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
