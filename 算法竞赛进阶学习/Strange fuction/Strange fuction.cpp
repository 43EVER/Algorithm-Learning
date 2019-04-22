// Strange fuction.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const double EPS = 1e-7;

double y;

double f(double x) {
	return 6.0 * x * x * x * x * x * x * x + 8 * x * x * x * x * x * x + 7 * x * x * x + 5 * x * x - y * x;
}

double solve() {
	double l = 0.0, r = 100.0;
	while (l + EPS < r) {
		double lmid = l + (r - l) / 3;
		double rmid = r - (r - l) / 3;
		if (f(lmid) > f(rmid))
			l = lmid;
		else
			r = rmid;
	}
	return l;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> y;
		cout << fixed << setprecision(4) << f(solve()) << endl;
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
