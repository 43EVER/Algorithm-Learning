// C. Neko does Maths.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	long long ans = lcm(a, b);
	int ansk = 0;
	for (int i = 1; i < 1000000; i++) {
		int j = i * 10;
		bool has_update = false;
		for (int k = (i - 1) * 10; k < j; k++) {
			long long tmp = lcm(a + k, b + k);
			if (tmp < ans) has_update = true, ans = tmp, ansk = k;
		//	cout << i << " " << k << " " << j << " " << tmp << endl;
		}
		if (!has_update)
			break;
	}

	cout << ansk << endl;
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
