// 乒乓球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stringstream ss2;
	char c;
	int biga = 0, bigb = 0;
	int tmpa = 0, tmpb = 0;
	while (cin >> c && c != 'E') {
		if (c == 'W')
			tmpa++, biga++;
		else if (c == 'L')
			tmpb++, bigb++;

		if ((tmpa >= 11 && tmpa - tmpb >= 2) || (tmpb >= 11 && tmpb - tmpa >= 2)) {
			cout << tmpa << ":" << tmpb << endl;
			tmpa = tmpb = 0;
		}
		if ((biga >= 21 && biga - bigb >= 2) || (bigb >= 21 && bigb - biga >= 2)) {
			ss2 << biga << ":" << bigb << endl;
			biga = bigb = 0;
		}
	}
	cout << tmpa << ":" << tmpb << endl << endl;
	ss2 << biga << ":" << bigb;
	cout << ss2.str();
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
