// 火柴棒等式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int cal_sticks(int n) {
	int s = 0;
	if (n == 0)
		s = cnt[0];
	else
		while (n)
			s += cnt[n % 10], n /= 10;
	return s;
}

int main() {
	int n;
	cin >> n;
	n -= 4;
	if (n <= 0) {
		cout << "0" << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < 1000; i++) {
		if (cal_sticks(i) < n)
		for (int j = 0; j < 1000; j++) {
			if (cal_sticks(i) + cal_sticks(j) >= n)
				continue;
			int k = i + j;
			int tmp = cal_sticks(i) + cal_sticks(j) + cal_sticks(k);
			if (tmp == n)
				ans++;
		}
	}

	cout << ans << endl;
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
