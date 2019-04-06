// 计算器的改良.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
using namespace std;

double l = 0.0, r = 0.0;
char ch;

void split(string& str) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '+' || str[i] == '-')
			if (i - 1 >= 0 && (isdigit(str[i - 1]) || isalpha(str[i - 1])))
				str.insert(i, " ");
}

void cal(stringstream& s, bool left) {
	string tmp;
	while (s >> tmp) {
		int n_cnt = 0;
		string tmp2;
		for (int i = 0; i < tmp.length(); i++) {
			if (tmp[i] == '-')
				n_cnt++;
			else if (tmp[i] == '+')
				continue;
			else
				tmp2.push_back(tmp[i]);
		}
		if (isalpha(tmp2.back())) {
			ch = tmp2.back();
			int res = 0;
			if (tmp2.length() == 1) {
				res = 1;
			}
			else {
				tmp2 = tmp2.substr(0, tmp2.length() - 1);
				res = atoi(tmp2.c_str());
			}
			if (!left)
				res = -res;
			if (n_cnt % 2 == 1)
				l -= res;
			else
				l += res;
		}
		else {
			int res = atoi(tmp2.c_str());
			if (left)
				res = -res;
			if (n_cnt % 2 == 1)
				r -= res;
			else
				r += res;
		}
	}
}

int main() {
	string str, left_s, right_s;
	cin >> str;
	int pos = str.find('=');
	left_s = str.substr(0, pos), right_s = str.substr(pos + 1, str.length() - pos - 1);
	split(left_s), split(right_s);

	stringstream ls(left_s), rs(right_s);
	cal(ls, true);
	cal(rs, false);
	cout << ch << "=";
	cout << fixed << setprecision(3) << r / l + 0.0 << endl;
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
