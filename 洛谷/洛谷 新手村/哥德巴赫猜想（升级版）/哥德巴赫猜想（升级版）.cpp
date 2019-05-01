// 哥德巴赫猜想（升级版）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

set<int> s;

void f(int n) {
	auto it1 = s.begin();
	while (it1 != s.end()) {
		auto it2 = s.begin();
		while (it2 != s.end()) {
			int i = n - *it1 - *it2;
			if (s.count(i)) {
				cout << *it1 << " " << *it2 << " " << i << endl;
				return;
			}
			it2++;
		}
		it1++;
	}
}

int main() {
	s.insert({ 2, 3 });
	for (int i = 5; i <= 20000; i++) {
		bool is = true;
		auto it = s.begin();
		while (it != s.end() && *it <= sqrt(i)) {
			if (i % *it == 0)
				is = false;
			it++;
		}
		if (is)
			s.insert(i);
	}

	int n;
	cin >> n;
	f(n);
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
