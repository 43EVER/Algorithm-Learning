// 是否同一棵二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct TNode {
	TNode *left;
	int key;
	TNode *right;
	bool flag;

	TNode(int data) {
		this->left = nullptr;
		this->key = data;
		this->right = nullptr;
		this->flag = false;
	}
};

TNode *insert(int data, TNode * t) {
	if (t == nullptr)
		return new TNode(data);

	if (data < t->key)
		t->left = insert(data, t->left);
	else
		t->right = insert(data, t->right);

	return t;
}

TNode *make(int n) {
	int tmp;
	TNode *t = nullptr;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		t = insert(tmp, t);
	}

	return t;
}

void pre(TNode *t) {
	if (!t) return;

	cout << t->key << " ";
	pre(t->left);
	pre(t->right);
}

bool judge(int data, TNode *t) {
	TNode *tmp = t;
	
	while (tmp) {
		if (data < tmp->key) {
			if (!tmp->flag)
				return false;
			tmp = tmp->left;
		}
		else if (data > tmp->key) {
			if (!tmp->flag)
				return false;
			tmp = tmp->right;
		}
		else {
			tmp->flag = true;
			return true;
		}
	}

	return false;
}

void reset(TNode *t) {
	if (!t) return;

	t->flag = false;
	reset(t->left);
	reset(t->right);
}

int main() {
	int n, T;

	while (cin >> n) {
		if (!n) break;
		cin >> T;
		TNode *t = make(n);
		while (T--) {
			bool isSolve = false;
			int tmp;

			for (int i = 0; i < n; ++i) {
				cin >> tmp;
				if (!isSolve) {
					if (judge(tmp, t) == false) {
						isSolve = true;
						cout << "No" << endl;
					}
				}
			}

			reset(t);

			if (!isSolve)
				cout << "Yes" << endl;
		}
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
