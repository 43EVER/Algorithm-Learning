﻿// A. Neko Finds Grapes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 100005;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0, tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) a1++;
		else a2++;
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) b1++;
		else b2++;
	}

	int ans = 0;
	ans += min(b1, a2);
	ans += min(a1, b2);

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
