// 数字反转（升级版）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std; 

void ff(string& s) {
	int i = 0;
	while (i < s.length() - 1) {
		if (s[i] != '0')
			break;
		i++;
	}
	s = s.substr(i, s.length() - i);
}

string f1(string& s, bool b = true) {
	ff(s);
	reverse(s.begin(), s.end());
	if (b) ff(s);
	return s;
}

int main() {
	string src, str1, str2;
	int pos;
	cin >> src;
	if ((pos = src.find('.')) != src.npos || (pos = src.find('/')) != src.npos) {
		str1 = src.substr(0, pos);
		str2 = src.substr(pos + 1, src.length() - pos - 1);
		cout << f1(str1);
		if (src[pos] == '.')
			cout << "." << f1(str2, false);
		else
			cout << "/" << f1(str2);
	}
	else {
		if (src.back() == '%') {
			str1 = src.substr(0, src.length() - 1);
			cout << f1(str1) << "%";
		}
		else
			cout << f1(src);
	}
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
