// POJ2054 Color a Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
using namespace std;

struct Node {
	int father, value;
	int price, num;
	bool canUse;
	double cmp;
} nodes[1000 + 5];

int n, root;

int find_max() {
	int idx = 0;
	double max_value = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		if (nodes[i].canUse && nodes[i].cmp > max_value)
			idx = i, max_value = nodes[i].cmp;
	return idx;
}

int find(int i) {
	if (i != nodes[i].father && nodes[nodes[i].father].canUse == false)
		return nodes[i].father = find(nodes[i].father);
	return nodes[i].father;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int v1, v2;
	while (cin >> n >> root) {
		if (n == 0) break;
		for (int i = 1; i <= n; i++) cin >> nodes[i].price, nodes[i].father = i, nodes[i].value = nodes[i].price, nodes[i].num = 1, nodes[i].canUse = true, nodes[i].cmp = nodes[i].price;
		nodes[root].canUse = false;
		for (int i = 1; i < n; i++) {
			cin >> v1 >> v2;
			nodes[v2].father = v1;
		}
		int pos = find_max();
		while (pos) {
			int father = find(pos);
			nodes[father].value += nodes[pos].value + nodes[father].num * nodes[pos].price;
			nodes[father].price += nodes[pos].price, nodes[father].num += nodes[pos].num;
			nodes[father].cmp = nodes[father].price * 1.0 / nodes[father].num;
			nodes[pos].canUse = false;
			pos = find_max();
		}
		cout << nodes[root].value << endl;
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
