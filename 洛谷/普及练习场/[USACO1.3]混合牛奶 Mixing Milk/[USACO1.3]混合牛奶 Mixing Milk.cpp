// [USACO1.3]混合牛奶 Mixing Milk.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int price, w;

	friend bool operator< (const Node& a, const Node& b) {
		return a.price < b.price;
	}
};

Node a[5000 + 10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].price >> a[i].w;

	sort(a, a + n);

	int money = 0;

	for (int i = 0; i < n; i++) {
		if (w >= a[i].w)
			money += a[i].w * a[i].price, w -= a[i].w;
		else {
			money += a[i].price * w;
			break;
		}
	}

	cout << int(money) << endl;
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
