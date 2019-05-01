// 潜伏者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	map<char, int> m1, m2;
	int cnt = 0;
	string ciphertext, plaintext;
	cin >> ciphertext >> plaintext;

	for (int i = 0; i < ciphertext.length(); i++) {
		char c1 = ciphertext[i];
		char c2 = plaintext[i];

		if ( (m1[c1] == m2[c2] && m1[c1] == 0) ||
			(c1 == m2[c2] && c2 == m1[c1]) ) {
			if (m1[c1] == 0)
				cnt++;
			m1[c1] = int(c2);
			m2[c2] = int(c1);
		}
		else {
			cout << "Failed";
			return 0;
		}
	}

	if (cnt < 26) {
		cout << "Failed";
		return 0;
	}
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.length(); i++) {
		cout << char( m1[tmp[i]] );
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
