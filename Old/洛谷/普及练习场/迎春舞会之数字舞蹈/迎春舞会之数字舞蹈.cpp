// 迎春舞会之数字舞蹈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int main() {
	vector<string> nums = {
	"-|| ||-", "  |  | ", "- |-| -",
	"- |- |-", " ||- | ", "-| - |-", "-| -||-",
	"- |  | ", "-||-||-", "-||- |-" };
	int size;
	string str;

	cin >> size >> str;
	for (int pos = 0; pos < 7; pos++) {
		if (pos == 2 || pos == 5)
			continue;
		if (!(pos % 3)) {
			for (auto c : str) {
				cout << ' ';
				for (int i = 0; i < size; i++)
					cout << nums[c - '0'][pos];
				cout << "  ";
			}
			cout << endl;
		}
		else {
			for (int i = 0; i < size; i++) {
				for (auto c : str) {
					cout << nums[c - '0'][pos];
					for (int j = 0; j < size; j++)
						cout << ' ';
					cout << nums[c - '0'][pos + 1] << ' ';
				}
				cout << endl;
			}
		}
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
