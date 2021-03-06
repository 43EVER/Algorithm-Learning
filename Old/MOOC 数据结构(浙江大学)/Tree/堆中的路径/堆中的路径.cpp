// 堆中的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void preDownMinHeap(vector<int> &h, int p) {
	int x = h[p];
	int parent = p;
	while (parent * 2 < h.size()) {
		int child = parent * 2;
		
		if (child + 1 < h.size() && h[child] > h[child + 1])
			child += 1;

		if (x > h[child])
			h[parent] = h[child];
		else
			break;

		parent = child;
	}
	h[parent] = x;
}

void makeMinHeap(vector<int> &h) {
	for (int i = (h.size() - 1) / 2; i >= 1; i--)
		preDownMinHeap(h, i);
}

void insertMinHeap(vector<int> &h, int key) {
	h.push_back(key);
	int i = h.size() - 1;

	while (key < h[i / 2]) {
		h[i] = h[i / 2];
		i /= 2;
	}
	h[i] = key;
}

int main() {
	vector<int> h;
	int n, m, tmp;

	cin >> n >> m;
	h.push_back(-0X3F3F3F3F);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		insertMinHeap(h, tmp);
	}

	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << h[tmp];
		while (tmp / 2 > 0) {
			cout << " " << h[tmp / 2];
			tmp /= 2;
		}
		cout << endl;
	}

	return 0;
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
