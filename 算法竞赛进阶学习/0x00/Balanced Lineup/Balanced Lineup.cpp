// Balanced Lineup.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 500005;
int a[N], min_range[N][20], max_range[N][20];
int n;

void st_pre() {
	for (int i = 1; i <= n; i++) min_range[i][0] = max_range[i][0] = a[i];
	int t = log2(n) + 1;
	for (int j = 1; j < t; j++)
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			min_range[i][j] = min(min_range[i][j - 1], min_range[i + (1 << (j - 1))][j - 1]);
			max_range[i][j] = max(max_range[i][j - 1], max_range[i + (1 << (j - 1))][j - 1]);
		}
}

int query(int l, int r) {
	int k = log2(r - l + 1); 
	int tmp1 = max(max_range[l][k], max_range[r - (1 << k) + 1][k]);
	int tmp2 = min(min_range[l][k], min_range[r - (1 << k) + 1][k]);
	//cout << l << " " << r << " " << tmp1 << " " << tmp2 << endl;
	return tmp1 - tmp2;
		
}

int main() {
	int k, l, r;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	st_pre();
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", query(l, r));
	}
	return 0;
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
