// 字符串的展开.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

string str;
int p1, p2, p3;

string f(int i) {
	char pre = '\0', next = '\0';
	if (i - 1 >= 0)
		pre = str[i - 1];
	if (i + 1 < str.length() )
		next = str[i + 1];

	if (pre == '\0' || pre == '-' || next == '\0' || next == '-')
		return "-";

	if (pre >= next || (!isalpha(pre) != !isalpha(next) ) )
		return "-";
	else if (pre + 1 == next)
		return "";

	string str;
	for (char ch = pre + 1; ch != next; ch++)
		str.push_back(ch);
	
	if (p1 == 2 && isalpha(pre))
		transform(str.begin(), str.end(), str.begin(), ::toupper);
	else if (p1 == 3)
		transform(str.begin(), str.end(), str.begin(), [](char a) {return '*'; });
	if (p3 == 2)
		reverse(str.begin(), str.end());
	if (p2 > 1) {
		string tmp;
		for (char c : str)
			for (int i = 0; i < p2; i++)
				tmp.push_back(c);
		str = tmp;
	}
	return str;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> p1 >> p2 >> p3;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-')
			cout << f(i);
		else
			cout << str[i];
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
