// Increasing Subsequence (easy).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	deque<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int i = 0, j = n - 1;
	int now = -0x3f3f3f3f;
	vector<char> ans;
	while (i <= j) {
		if (now < a[i] && now < a[j])
			if (a[i] < a[j]) ans.push_back('L'), now = a[i], i++;
			else ans.push_back('R'), now = a[j], j--;
		else if (now < a[i])
			ans.push_back('L'), now = a[i], i++;
		else if (now < a[j])
			ans.push_back('R'), now = a[j], j--;
		else
			break;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i];
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
