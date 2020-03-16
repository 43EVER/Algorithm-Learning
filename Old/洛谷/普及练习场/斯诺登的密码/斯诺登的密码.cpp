// 斯诺登的密码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cctype>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

map<string, int> nums = {
{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
{"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10},
{"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15},
{"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20},
{"a", 1}, {"both", 2}, {"another", 3}, {"first", 1}, {"second", 2}, {"third", 3}
};

int main() {
	vector<int> a;
	string tmp;
	while (cin >> tmp) {
		if (isdigit(tmp[0]))
			tmp[0] = tolower(tmp[0]);
		if (nums[tmp] != 0)
			a.push_back((nums[tmp] * nums[tmp]) % 100);
	}

	sort(a.begin(), a.end());

	bool flag = false;
	long long int res = 0;
	for (int i = 0; i < a.size(); i++) {
		res += a[i];
		res *= 100;
	}
	cout << res / 100 << endl;
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
