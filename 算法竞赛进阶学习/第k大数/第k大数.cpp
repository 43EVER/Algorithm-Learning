﻿// 第k大数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
int a[N];

int find_k(int l, int r, int k) {
	if (l > r)
		return 0;
	int key = a[l], i = l, j = r;
	while (i < j) {
		while (j > i && a[j] >= key) j--;
		swap(a[i], a[j]);
		while (i < j && a[i] <= key) i++;
		swap(a[i], a[j]);
	}
	if (r + 1 - i > k)
		return find_k(i + 1, r, k);
	else if (r + 1 - i == k)
		return a[i];
	else
		return find_k(l, i - 1, k - (r + 1 + i));
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << find_k(0, n - 1, k);
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
