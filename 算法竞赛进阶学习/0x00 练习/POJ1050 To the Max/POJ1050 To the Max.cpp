// POJ1050 To the Max.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

// 降维打击，一维最大连续子序列和
// 扩展到二维

const int N = 505;
int a[N][N], b[N][N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j] + b[i - 1][j];
		}

	int max_sum = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			int sum = 0;
			for (int k = 1; k <= n; k++) {
				if (sum > 0) sum += b[j][k] - b[i - 1][k];
				else sum = b[j][k] - b[i - 1][k];
				max_sum = max(sum, max_sum);
			}
		}

	cout << max_sum << endl;
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
