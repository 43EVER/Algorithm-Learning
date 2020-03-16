// Fractal Streets.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long ll;

pair<ll, ll> calc(int n, ll m) {
	if (n == 0) return { 0, 0 };
	ll block_size = 1 << (2 * n - 2), block_len = 1 << (n - 1);
	ll block_pos = m / block_size;
	pair<ll, ll> pos = calc(n - 1, m % block_size);
	switch (block_pos) {
	case 0:
		return { pos.second, pos.first };
	case 1:
		return { pos.first, pos.second + block_len };
	case 2:
		return { pos.first + block_len, pos.second + block_len };
	case 3:
		return { 2 * block_len - 1 - pos.second, block_len - 1 - pos.first };
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		ll a, b;
		cin >> n >> a >> b;
		pair<ll, ll> p1 = calc(n, a - 1), p2 = calc(n, b - 1);
		double ans = 10 * sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
		cout << fixed << setprecision(0) << ans << endl;
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
