// Tree Traversals Again.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

vector<int> pre, in, post;


void postorder(int root, int from, int to) {
	if (to < from) return;
	int i = from;
	while (i < to && in[i] != pre[root]) i++;
	postorder(root + 1, from, i - 1);
	postorder(root + 1 + i - from, i + 1, to);
	post.push_back(pre[root]);
}

int main() {
	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < 2 * n; i++) {
		string op;
		cin >> op;
		if (op.length() == 4) {
			int value;
			cin >> value;
			pre.push_back(value);
			s.push(value);
		} else {
			in.push_back(s.top());
			s.pop();
		}
	}
	postorder(0, 0, n - 1);
	cout << post[0];
	for (int i = 1; i < post.size(); i++)
		cout << " " << post[i];
	cout << endl;

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
