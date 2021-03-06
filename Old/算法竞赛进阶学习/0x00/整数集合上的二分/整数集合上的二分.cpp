﻿// 整数集合上的二分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

int a[100];

//a[l] <= key
int find(int l, int r, int key) {
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (a[mid] <= key) l = mid;
		else r = mid - 1;
	}
}

//a[l] >= key

int find(int l, int r, int key) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (a[mid] >= key) r = mid;
		else l = mid + 1;
	}
}

int find(double l, double r, double x) {
	double mid;
	while (l + 1e-5 <= r) {
		mid = (l + r) / 2;
		if (x - mid >= 1e5) l = mid + 1e5;
		else r = mid - 1e5;
	}
	return l;
}

int main() {
	int n, key;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> key;
	cout << find(0, n - 1, key) << endl;
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
