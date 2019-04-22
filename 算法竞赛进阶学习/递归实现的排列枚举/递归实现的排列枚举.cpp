// 递归实现的排列枚举.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> chosen(13);
vector<int> order(13);

void calc(int k) {
	if (k == n + 1) {
		for (int i = 1; i <= n; i++)
			cout << order[i] << " ";
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chosen[i])
			continue;
		order[k] = i;
		chosen[i] = true;
		calc(k + 1);
		chosen[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n)
		calc(1);
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
