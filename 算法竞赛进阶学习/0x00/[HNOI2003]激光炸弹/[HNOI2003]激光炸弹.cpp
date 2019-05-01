// [HNOI2003]激光炸弹.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX = 5000;

int mp[MAX + 5][MAX + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r, xi, yi, vi;
	cin >> n >> r;
	int maxxi = r, maxyi = r;
	for (int i = 0; i < n; i++) {
		cin >> xi >> yi >> vi;
		++xi, ++yi;
		mp[xi][yi] += vi;
		maxxi = max(maxxi, xi);
		maxyi = max(maxyi, yi);
	}
	for (int x = 1; x <= maxxi; x++)
		for (int y = 1; y <= maxyi + 1; y++)
			mp[x][y] += mp[x - 1][y] + mp[x][y - 1] - mp[x - 1][y - 1];

	int ans = 0;
	for (int x = r; x <= maxxi; x++)
		for (int y = r; y <= maxyi + 1; y++)
			ans = max(ans, mp[x][y] - mp[x - r][y] - mp[x][y - r] + mp[x - r][y - r]);

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
