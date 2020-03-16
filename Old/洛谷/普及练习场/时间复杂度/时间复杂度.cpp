// 时间复杂度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

vector<bool> used;

int compare(const string& str1, const string& str2) {
	if (str1[0] == 'n') {
		if (str2[0] == 'n')
			return 0;
		return -1;
	}
	
	if (str2[0] == 'n') {
		return 1;
	}
	
	int num1 = atoi(str1.c_str()), num2 = atoi(str2.c_str());
	if (num1 <= num2)
		return 0;
	return -1;
}

int peekChar(stringstream& ss) {
	while (ss.peek() == ' ')
		ss.get();
	return ss.peek();
}

int loops(stringstream& program, bool canCount = true);
int loop(stringstream& program, bool canCount = true);

int main() {

	//freopen("./a.in", "r", stdin);

	int t;
	used = vector<bool>(26);
	cin >> t;

	while (t--) {
		fill(used.begin(), used.end(), false);

		int lineCnt, expectedComplexity = 0;
		cin >> lineCnt;

		string complexity;
		cin >> complexity; getchar();

		if (complexity.find('n') != complexity.npos)
			sscanf(complexity.c_str(), "O(n^%d)", &expectedComplexity);

		stringstream program;
		while (lineCnt--) {
			string tmp;
			getline(cin, tmp);
			program << tmp << " ";
		}
#ifdef DEBUG
		cout << "-------------------" << endl;
		cout << program.str() << endl;
		cout << "-------------------" << endl;
#endif // DEBUG

		int calComplexity = loops(program);
		if (calComplexity == -1 || peekChar(program) != -1)
			cout << "ERR" << endl;
		else if (calComplexity == expectedComplexity)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
}

int loops(stringstream& program, bool canCount) {
	int complexity = 0;
	while (peekChar(program) == 'F') {
		int tmp = loop(program);
		if (tmp == -1)
			return -1;
		complexity = max(complexity, tmp);
	}
	if (canCount)
		return complexity;
	return 0;
}

int loop(stringstream& program, bool canCount) {
	program.get();
	int complexity = 0;
	char var;
	string from, to;

	program >> var >> from >> to;

	if (used[var - 'a'])
		return -1;
	used[var - 'a'] = true;

	bool needCount = (compare(from, to) >= 0 ? true : false);
	if (compare(from, to) == 1)
		complexity += 1;

	if (peekChar(program) == 'F') {
		int tmp = loops(program, needCount);
		if (tmp == -1)
			return -1;
		complexity += tmp;
	}
	used[var - 'a'] = false;
	if (peekChar(program) == 'E')
		program.get();
	else
		return -1;

	if (needCount)
		return complexity;
	return 0;
}
