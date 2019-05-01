// 01迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int f[1000000 + 10], h[1000000 + 10];
char mp[2][1000 + 10];

int find(int i) {
	return i == f[i] ? i : f[i] = find(f[i]);
}

void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i != j) f[i] = j, h[j] += h[i];
}

int main() {
	int n, m, si, sj;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mp[i & 1];
		for (int j = 0; j < n; j++) {
			f[i * n + j] = i * n + j, h[i * n + j] = 1;
			if (i != 0 && mp[i & 1][j] != mp[(i - 1) & 1][j]) join(i * n + j, (i - 1) * n + j);
			if (j != 0 && mp[i & 1][j] != mp[i & 1][j - 1]) join(i * n + j, i * n + j - 1);
		}
	}
	while (m--) {
		cin >> si >> sj;
		cout << h[find((si - 1) * n + sj - 1)] << endl;
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
