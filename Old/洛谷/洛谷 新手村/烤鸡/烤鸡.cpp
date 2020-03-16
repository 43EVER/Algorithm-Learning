﻿// 烤鸡.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int way[10] = {};
stringstream ss;
int ans = 0;

void dfs(int i , int n) {
	if ((10 - i) * 3 < n)
		return;

	if (i == 10) {
		if (n == 0) {
			ss << way[0];
			for (int i = 1; i < 10; i++)
				ss << " " << way[i];
			ss << endl;
			ans++;
		}
		return;
	}

	for (int j = 1; j < 4; j++) {
		way[i] = j;
		dfs(i + 1, n - j);
	}
}

int main() {
	int n;
	cin >> n;
	dfs(0, n);
	cout << ans << endl;
	if (ans) {
		cout << ss.str();
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