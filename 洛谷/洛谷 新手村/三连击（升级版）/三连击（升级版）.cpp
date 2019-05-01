// 三连击（升级版）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int a, b, c, cnt = 0;
	cin >> a >> b >> c;
	for (int i = 123; i <= 987; i++) {
		if (i % a == 0) {
			int j = i * b / a;
			int k = i * c / a;

			if (j >= 1000 || k >= 1000)
				continue;

			int aa[10] = {};
			string str1 = to_string(i) + to_string(j) + to_string(k);

			bool ok = true;
			for (char c : str1) {
				aa[c - '0']++;
				if (aa[c - '0'] == 2 || c == '0') {
					ok = false;
					break;
				}
			}
			if (ok)
				cout << i << " " << j << " " << k << endl, cnt++;
		}
	}
	if (!cnt)
		cout << "No!!!" << endl;
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
