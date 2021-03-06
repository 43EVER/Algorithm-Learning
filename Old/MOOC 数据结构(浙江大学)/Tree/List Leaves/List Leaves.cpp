// List Leaves.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TNode {
	int left;
	int right;
};

vector<TNode> A;
queue<int> q;
vector<int> d;

vector<TNode> NewTree()
{
	int n;
	vector<TNode> tree;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char left, right;
		cin >> left >> right;
		tree.push_back({ left == '-' ? -1 : left - '0', right == '-' ? -1 : right - '0' });
	}

	return tree;
}

int Root(const vector<TNode> & tree)
{
	vector<bool> use(tree.size(), false);
	for (TNode t : tree)
	{
		if (t.left != -1)
			use[t.left] = true;
		if (t.right != -1)
			use[t.right] = true;
	}

	for (int i = 0; i < use.size(); i++)
	{
		if (use[i] == false)
			return i;
	}

	return -1;
}

void Print(int root)
{
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if (now == -1)
			continue;

		if (A[now].left != -1)
			q.push(A[now].left);
		if (A[now].right != -1)
			q.push(A[now].right);

		if (A[now].left == A[now].right && A[now].left == -1)
			d.push_back(now);

	}
}

int main()
{
	A = NewTree();
	Print(Root(A));

	if (d.size() > 0)
		cout << d[0];

	for (int i = 1; i < d.size(); i++)
		cout << " " << d[i];
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
