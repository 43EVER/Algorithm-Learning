// POJ2083 Fractal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[1000][1000];

int mypowe(int d) {
	int ans = 1;
	for (int i = 1; i <= d; i++)
		ans *= 3;
	return ans;
}

void dfs(int cur, int x, int y) {
	if (cur == 1) {
		a[x][y] = 'X';
		return;
	}
	int s = mypowe(cur - 2);
	dfs(cur - 1, x, y);
	dfs(cur - 1, x, y + 2 * s);
	dfs(cur - 1, x + s, y + s);
	dfs(cur - 1, x + 2 * s, y);
	dfs(cur - 1, x + 2 * s, y + 2 * s);
}

int main() {
	int n;
	while (cin >> n && n != -1) {
		memset(a, ' ', sizeof(a));
		dfs(n, 1, 1);
		int s = mypowe(n - 1);
		for (int i = 1; i <= s; i++)
			a[i][s + 1] = '\0';
		for (int i = 1; i <= s; i++)
			cout << (1 + a[i]) << endl;
		cout << "-" << endl;
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
