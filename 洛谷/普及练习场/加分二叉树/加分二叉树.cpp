// 加分二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

int a[30], plan[30];
int result[30][30], way[30][30];
int cnt;

int dfs(int leftpos, int rightpos) {
	if (leftpos == rightpos) {
		way[leftpos][rightpos] = leftpos;
		return a[leftpos];
	}
	else if (leftpos > rightpos || leftpos < 0) {
		return 1;
	}

	if (result[leftpos][rightpos]) {
		return result[leftpos][rightpos];
	}

	for (int pos = leftpos; pos <= rightpos; pos++) {
		int tmp1 = dfs(leftpos, pos - 1);
		int tmp2 = dfs(pos + 1, rightpos);
		int tmp = tmp1 * tmp2 + a[pos];
		if (tmp > result[leftpos][rightpos]) {
			way[leftpos][rightpos] = pos;
			result[leftpos][rightpos] = tmp;
		}
	}
	return result[leftpos][rightpos];
}

void print(int leftpos, int rightpos) {
	if (leftpos == rightpos) {
		cout << way[leftpos][rightpos] + 1 << " ";
		return;
	}
	else if (leftpos > rightpos) {
		return;
	}

	int rootpos = way[leftpos][rightpos];
	cout << rootpos << " ";
	print(leftpos, rootpos - 1);
	print(rootpos + 1, rightpos);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << dfs(0, n - 1) << endl;
	print(0, n - 1);
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
