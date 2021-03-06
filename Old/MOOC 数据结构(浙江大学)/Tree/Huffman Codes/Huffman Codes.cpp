// Huffman Codes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <functional>

struct Node {
	int weight;
	char ch;
	Node *left, *right;
};

class Comparator {
public:
	bool operator() (const Node *a, const Node *b) {
		return a->weight > b->weight;
	}
};

std::map<char, int> data;

Node *Hufferman(std::priority_queue<Node*, std::vector<Node*>, Comparator> q) {
	while (q.size() > 1) {
		Node *left = q.top(); q.pop();
		Node *right = q.top(); q.pop();
		Node *tmp = new Node;
		tmp->left = left;
		tmp->right = right;
		tmp->ch = '\0';
		tmp->weight = left->weight + right->weight;
		q.push(tmp);
	}

	return q.top();
}

int getWpl(Node *t) {
	if (t == nullptr)
		return 0;

	if (t->ch != '\0') {
		return 0;
	}

	return t->weight + getWpl(t->left) + getWpl(t->right);
}

bool judge1(int wpl, std::map<char, std::string> &data2) {
	int wpl2 = 0;
	for (std::map<char, std::string>::iterator it = data2.begin(); it != data2.end(); it++) {
		if (data.find(it->first) == data.end())
			return false;
		wpl2 += it->second.length() * data.find(it->first)->second;
	}

	return wpl == wpl2;
}

bool judge2(std::map<char, std::string> &data2) {
	for (std::map<char, std::string>::iterator it = data2.begin(); it != data2.end(); it++) {
		std::map<char, std::string>::iterator it2 = it; it2++;
		while (it2 != data2.end()) {
			int i = 0, j = 0;
			while (i < it->second.length() && j < it2->second.length()) {
				if (it->second[i] == it2->second[j])
					i++, j++;
				else
					break;
			}
			if (i == it->second.length() || j == it2->second.length()) {
				//std::cout << it->second << " " << it2->second << std::endl;
				return false;
			}
			it2++;
		}
	}
	return true;
}

int main() {
	int n, weight, m;
	char ch;
	std::priority_queue<Node*, std::vector<Node*>, Comparator> q;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> ch >> weight;
		Node* tmp = new Node;
		tmp->ch = ch;
		tmp->weight = weight;
		tmp->left = nullptr;
		tmp->right = nullptr;
		q.push(tmp);
		data[ch] = weight;
	}

	Node *ht = Hufferman(q);
	int wpl = getWpl(ht);

	std::cin >> m;
	while (m--) {
		std::map<char, std::string> data2;
		for (int i = 0; i < n; i++) {
			char ch;
			std::string tmp;
			std::cin >> ch >> tmp;
			data2[ch] = tmp;
		}
		std::cout << ((judge1(wpl, data2) && judge2(data2)) ? "Yes" : "No") << std::endl;
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
