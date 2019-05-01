// Frequent values.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1e6 + 5;
int a[N], f[N][30], b[N];
int n, q;

void pre() {
	for (int i = 1; i <= n; i++) f[i][0] = a[i];
	int t = log2(n) + 1;
	for (int j = 1; j < t; j++)
		for (int i = 1; i <= n - (1 << j) + 1; i++)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
	int l, r;
	while (2 == scanf("%d %d", &n, &q)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			if (i == 1) a[i] == 1;
			else if (b[i] == b[i - 1]) a[i] = a[i - 1] + 1;
			else a[i] = 1;
		}
		pre();
		while (q--) {
			scanf("%d %d", &l, &r);
			int i = l + 1;
			while (i <= r && b[i] == b[i - 1]) i++;
			int ans = i - l;
			if (i <= r) ans = max(ans, query(i, r));
			cout << ans << endl;
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
