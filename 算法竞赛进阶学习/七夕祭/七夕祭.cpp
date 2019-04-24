// 七夕祭.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
using namespace std;

const int N = 100005;
const double EPS = 1e-3;

int rows[N], cols[N];
int n, m, t, row, col, _size;

bool equal(double a, double b) {
	if (abs(a - b) < EPS)
		return true;
	return false;
}

int f(int a[N], int len) {
	vector<int> s(len + 1);
	for (int i = 1; i <= 1; i++)
		s[i] = s[i - 1] + a[i] - _size;
	sort(s.begin() + 1, s.end());
	int ans = 0, pos = (len % 2 == 1 ? (len + 1) / 2 : len / 2);
	for (int i = 1; i <= len; i++)
		ans += abs(s[pos] - s[i]);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<pair<int, int> > used;
	cin >> n >> m >> t;
	for (int i = 0; i < t; i++) {
		cin >> row >> col;
		if (used.count({ row, col }))
			continue;
		rows[row]++;
		cols[col]++;
		used.insert({ row, col });
	}

	bool canRow = false, canCol = false;
	int ans = -0x3f3f3f3f;
	if (equal(double(t) / n, t / n)) {
		canRow = true;
		_size = t / n;
		int cnt = f(rows, n);
		cout << cnt << endl;
		ans = cnt;
	}
	if (equal(double(t) / m, t / m)) {
		canCol = true;
		_size = t / m;
		int cnt = f(cols, m);
		if (ans < 0) ans = cnt;
		else ans += cnt;
		cout << cnt << endl;
	}

	if (canRow || canCol) {
		if (canRow && canCol) cout << "both ";
		else if (canRow) cout << "row ";
		else cout << "column ";
		cout << ans;
	}
	else { cout << "impossible"; }
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
