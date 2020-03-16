// Genius ACM.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;
int a[N], b[N], c[N];

inline long long cal(int a, int b) {
	long long c = (a - b);
	return c * c;
}

int n, m;
long long k;

inline bool solve(int l, int mid, int r) {
	for (int k = l; k <= r; k++) c[k] = a[k];
	sort(a + mid + 1, a + r + 1);
	int i = l, j = mid + 1, cnt = m;
	long long ans = 0;
	for (int k = l; k <= r; k++)
		if (j > r || i <= mid && a[i] <= a[j]) b[k] = a[i++];
		else b[k] = a[j++];
	for (int k = l; k <= r; k++) a[k] = b[k];
	i = l, j = r;
	while (i < j && cnt--) ans += cal(a[i++], a[j--]);
	if (ans > k) for (int k = l; k <= r; k++) a[k] = c[k];
	return ans <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int batches = 0, startpos = 1;
		while (startpos <= n) {
			int p = 1, l = startpos, r = startpos;
			while (p)
				if (r + p > n) p >>= 1;
				else if (solve(l, r, r + p)) r += p, p <<= 1;
				else p >>= 1;
			++batches, startpos = r + 1;
		}
		cout << batches << endl;
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
