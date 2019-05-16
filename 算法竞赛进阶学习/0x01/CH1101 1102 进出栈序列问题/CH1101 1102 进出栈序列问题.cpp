// CH1101 1102 进出栈序列问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

void add(string & a, string & b) {
	int tmp = 0, i;
	for (i = 0; i < a.length() || i < b.length(); i++) {
		if (i < a.length()) tmp += a[i];
		if (i < b.length()) tmp += b[i];
		
		if (tmp > a[i]) {
			if (i < a.length()) a.push_back(tmp % 10);
			else a[i] = tmp % 10;
			tmp /= 10;
		}
	}
	if (tmp) a.push_back(tmp % 10);
}

int main() {
	string a, b;
	while (cin >> a >> b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 0; i < a.length(); i++)
			a[i] -= '0';
		for (int i = 0; i < b.length(); i++)
			b[i] -= '0';
		add(a, b);
		for (int i = 0; i < a.length(); i++)
			a[i] += '0';
		reverse(a.begin(), a.end());
		cout << a << endl;
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
