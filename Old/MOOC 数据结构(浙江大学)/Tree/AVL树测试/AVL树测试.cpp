// AVL树测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::queue;

struct TNode {
	TNode *left;
	int key;
	TNode *right;

	TNode(int key) {
		this->key = key;
		this->left = nullptr;
		this->right = nullptr;
	}
};

int Height(TNode *t) {
	if (!t)
		return 0;

	return max(Height(t->left), Height(t->right)) + 1;
}

TNode * LL(TNode *t1) {
	TNode *t2 = t1->left;
	t1->left = t2->right;
	t2->right = t1;

	return t2;
}

TNode * RR(TNode *t1) {
	TNode *t2 = t1->right;
	t1->right = t2->left;
	t2->left = t1;

	return t2;
}

TNode * LR(TNode *t1) {
	t1->left = RR(t1->left);
	
	return LL(t1);
}

TNode * RL(TNode *t1) {
	t1->right = LL(t1->right);

	return RR(t1);
}

TNode * maximum(TNode *t) {
	return !t->right ? t : maximum(t->right);
}

TNode *minimum(TNode *t) {
	return !t->left ? t : minimum(t->left);
}

TNode * insert(TNode *t, int key) {
	if (t == nullptr)
		return new TNode(key);

	if (key < t->key) {
		t->left = insert(t->left, key);
		if (Height(t->left) - Height(t->right) == 2) {
			if (key < t->left->key)
				t = LL(t);
			else
				t = LR(t);
		}
	}
	else if (key > t->key) {
		t->right = insert(t->right, key);
		if (Height(t->right) - Height(t->left) == 2) {
			if (key < t->right->key)
				t = RL(t);
			else
				t = RR(t);
		}
	}

	return t;
}

TNode * remove(TNode *t, int key) {
	if (!t) 
		return nullptr;

	if (key < t->key) {
		t->left = remove(t->left, key);
		if (Height(t->right) - Height(t->left) == 2) {
			TNode *r = t->right;
			if (Height(r->left) > Height(t->right))
				t = RL(t);
			else
				t = RR(t);
		}
	}
	else if (key > t->key) {
		t->right = remove(t->right, key);
		if (Height(t->left) - Height(t->right) == 2) {
			TNode *l = t->left;
			if (Height(l->left) < Height(l->right))
				t = LR(t);
			else
				t = LL(t);
		}
	}
	else {
		if (t->left && t->right) {
			if (Height(t->left) > Height(t->right)) {
				t->key = maximum(t->left)->key;
				t->left = remove(t->left, t->key);
			}
			else {
				t->key = minimum(t->right)->key;
				t->right = remove(t->right, t->key);
			}
		}
		else {
			TNode *tmp = t;
			t = t->left ? t->left : t->right;
			free(tmp);
		}
	}

	return t;
}

void pre(TNode *t) {
	if (!t)
		return;
	cout << t << " " << t->left << " " << t->right << " " << t->key << endl;
	pre(t->left);
	pre(t->right);
}

int main() {
	TNode *t = nullptr;
	int n;
	
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			t = insert(t, tmp);
		}

		cout << t->key << endl;
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
