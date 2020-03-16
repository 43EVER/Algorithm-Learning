// 【模板】快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void Insert(Node** head, Node * insert) {
	Node* entry = *head;
	Node** ptr = head;
	while (entry != nullptr && entry->data < insert->data) {
		ptr = &(entry->next);
		entry = entry->next;
	}
	insert->next = entry;
	*ptr = insert;
}

void bucket_sort(vector<int> a) {
	int maxv = a[0];
	int minv = a[0];
	for (auto i : a) {
		if (i < minv)
			minv = i;
		if (i > maxv)
			maxv = i;
	}

	int k = (maxv - minv) / 100 + 1;
	vector<Node*> bucket(100);
	for (int i : a) {
		Node* insert = new Node{ i, nullptr };
		Insert(&bucket[(i - minv) / k], insert);
	}

	for (auto i : bucket) {
		auto ptr = i;
		while (ptr != nullptr) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	bucket_sort(a);
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
