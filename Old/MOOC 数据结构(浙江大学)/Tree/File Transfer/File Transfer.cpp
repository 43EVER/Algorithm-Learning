// File Transfer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> a;

int find(int root) {
	return a[root] == root ? root : a[root] = find(a[root]);
}

void combine(int x, int y) {
	a[find(x)] = a[find(y)];
}

int main() {
	int n;
	string tmp;

	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = i;

	while (cin >> tmp) {
		if (tmp == "S") {
			break;
		}
		else if (tmp == "C") {
			int x, y;
			cin >> x >> y;
			if (find(x) == find(y))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else {
			int x, y;
			cin >> x >> y;
			combine(x, y);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == i)
			cnt++;

	if (cnt == 1) {
		cout << "The network is connected." << endl;
	}
	else {
		cout << "There are " << cnt << " components." << endl;
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
