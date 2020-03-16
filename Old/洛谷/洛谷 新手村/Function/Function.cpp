// Function.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

long long arr[25][25][25];

long long f(long long a, long long b, long long c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return arr[20][20][20] = f(20, 20, 20);
	if (arr[a][b][c] != -1)
		return arr[a][b][c];
	if (a < b && b < c)
		return arr[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
	return arr[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
}

int main() {
	memset(arr, -1, sizeof(arr));

	long long a, b, c;
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, f(a, b, c));
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
