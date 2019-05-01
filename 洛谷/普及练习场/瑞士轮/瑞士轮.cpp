// 瑞士轮.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int score, idx, power;
};

bool cmp (const Node& a, const Node& b) {
	if (a.score != b.score)
		return b.score < a.score;
	return a.idx < b.idx;
}

Node a[200010];
Node tmp[200010];

void merge(int l, int m, int r) {
	int i = l, j = m;
	int cnt = 0;
	while (i < m && j < r) {
		if (cmp(tmp[i], tmp[j]))
			a[cnt++] = tmp[i++];
		else
			a[cnt++] = tmp[j++];
	}
	while (i < m)
		a[cnt++] = tmp[i++];
	while (j < r)
		a[cnt++] = tmp[j++];
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i].score, a[i].idx = i;
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i].power;

	sort(a, a + 2 * n, cmp);
	
	while (r--) {
		int l = 0, r = n;
		for (int i = 0; i < (n << 1); i += 2) {
			if (a[i].power > a[i + 1].power) {
				a[i].score++;
				tmp[l++] = a[i];
				tmp[r++] = a[i + 1];
			}
			else {
				a[i + 1].score++;
				tmp[l++] = a[i + 1];
				tmp[r++] = a[i];
			}
		}
		merge(0, l, r);
	}

	cout << a[q - 1].idx + 1 << endl;
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
