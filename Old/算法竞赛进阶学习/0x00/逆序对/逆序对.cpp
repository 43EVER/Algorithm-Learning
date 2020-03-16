// 逆序对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N], tmp[N];
int ans = 0;

void merge(int l, int mid, int r) {
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
		if (j > r || i <= mid && a[i] <= a[j]) tmp[k] = a[i++];
		else ans += mid + 1 - i, tmp[k] = a[j++];
	for (int k = l; k <= r; k++) a[k] = tmp[k];
}

void merge_sort(int l, int r) {
	if (l >= r) return;
	int m = (l + r) >> 1;
	merge_sort(l, m);
	merge_sort(m + 1, r);
	merge(l, m, r);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
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
