// 树的同构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
	int left;
	char data;
	int right;
};

vector<TNode> A, B;

vector<TNode> NewTree()
{
	int n;
	vector<TNode> tree;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char data, left, right;
		cin >> data >> left >> right;
		tree.push_back({ left == '-' ? -1 : left - '0', data, right == '-' ? -1 : right - '0' });
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

bool Isomorphism(int rootA, int rootB)
{
	if (rootA == -1 && rootB == -1)
		return true;
	else if (rootA == -1 && rootB != -1 || rootA != -1 && rootB == -1)
		return false;
	else if (A[rootA].data != B[rootB].data)
		return false;
	else
		return (Isomorphism(A[rootA].left, B[rootB].left) && Isomorphism(A[rootA].right, B[rootB].right)) ||
		(Isomorphism(A[rootA].left, B[rootB].right) && Isomorphism(A[rootA].right, B[rootB].left));
}

int main()
{
	A = NewTree();
	B = NewTree();

	if (Isomorphism(Root(A), Root(B)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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
