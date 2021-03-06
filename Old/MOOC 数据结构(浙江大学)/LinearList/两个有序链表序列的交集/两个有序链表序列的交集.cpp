// 两个有序链表序列的交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	vector<int> b;
	int temp;

	while (cin >> temp && temp != -1)
		a.push_back(temp);
	while (cin >> temp && temp != -1)
		b.push_back(temp);

	vector<int> c;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i] == b[j])
			c.push_back(a[i]), ++i, ++j;
		else if (a[i] < b[j])
			++i;
		else if (a[i] > b[j])
			++j;
	}

	if (c.empty())
		cout << "NULL";
	else
	{
		cout << c[0];
		for (int i = 1; i < c.size(); ++i)
			cout << " " << c[i];
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
