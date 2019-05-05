// POJ3714 Raid.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

const int N = 100000 + 5;

double ax[N], ay[N];

double cal(double x1, double y1, double x2, double y2) {
	return sqrt(pow(double(x1 - x2), 2) + pow(double(y1 - y2), 2));
}

int main() {
	int t, n;
	double x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> ax[i] >> ay[i];
		double ans = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			for (int j = 0; j < n; j++)
				ans = min(ans, cal(x, y, ax[j], ay[j]));
		}
		cout << fixed << setprecision(3) << ans << endl;
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
