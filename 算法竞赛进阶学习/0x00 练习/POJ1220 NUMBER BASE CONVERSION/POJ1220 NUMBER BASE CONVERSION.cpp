// POJ1220 NUMBER BASE CONVERSION.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <functional>
#include <map>
using namespace std;

map<char, int> m1;
map<int, char> m2;

void multi(string& s, int x, int base) {
	int tmp = 0;
	for (int i = 0; i < s.length(); i++) {
		tmp += m1[s[i]] * x;
		s[i] = m2[tmp % base];
		tmp /= base;
	}
	while (tmp) {
		s.push_back(m2[tmp % base]);
		tmp /= base;
	}
}

void add(string& res, string& x, int base) {
	string ans;
	int pos = max(res.length(), x.length());
	int i = 0, j = 0, tmp = 0;
	while (i < res.length() && j < res.length()) {
		tmp += m1[res[i++]] + m1[x[j++]];
		ans.push_back(m2[tmp % base]);
		tmp /= base;
	}
	while (i < res.length()) {
		tmp += m1[res[i++]];
		ans.push_back(m2[tmp % base]);
		tmp /= base;
	}
	while (j < x.length()) {
		tmp += m1[x[j++]];
		ans.push_back(m2[tmp % base]);
		tmp /= base;
	}
	while (tmp) {
		ans.push_back(m2[tmp % base]);
		tmp /= base;
	}
	res = ans;
}

int main() {
	int t, base1, base2, cnt = 0;
	for (int i = 0; i < 10; i++) m1['0' + i] = cnt, m2[cnt++] = '0' + i;
	for (int i = 0; i < 26; i++) m1['A' + i] = cnt, m2[cnt++] = 'A' + i;
	for (int i = 0; i < 26; i++) m1['a' + i] = cnt, m2[cnt++] = 'a' + i;

	string temp1 = "1", temp2 = "11";
	add(temp1, temp2, 2);
	cout << temp1 << endl;

	string str1, str2;
	cin >> t;
	while (t--) {
		cin >> base1 >> base2 >> str1;
		reverse(str1.begin(), str1.end());
		string pow = "1";
		str2 = "0";
		for (int i = 0; i < str1.length(); i++) {
			string tmp = pow;
			multi(tmp, m1[str1[i]], base1);
			add(str2, tmp, base2);
			multi(pow, base1, base1);
		}
		reverse(str2.begin(), str2.end());
		cout << str2 << endl;
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
