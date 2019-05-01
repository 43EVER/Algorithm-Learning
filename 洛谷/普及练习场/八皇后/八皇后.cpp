// 八皇后.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma optimize(3, "Ofast", "inline");
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 0;
int ans[13 + 5];
bool crossl[13 * 2 + 5], crossr[13 * 2 + 5], used[13];

void dfs(int pos) {
	if (pos == n) {
		++cnt;
		if (cnt <= 3) {
			cout << ans[0] + 1;
			for (int i = 1; i < n; i++)
				cout << " " << ans[i] + 1;
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!used[i] && !crossl[pos - i + n] && !crossr[pos + i]) {
			ans[pos] = i;
			used[i] = true;
			crossl[pos - i + n] = true;
			crossr[pos + i] = true;
			dfs(pos + 1);
			used[i] = false;
			crossl[pos - i + n] = false;
			crossr[pos + i] = false;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	dfs(0);
	cout << cnt << endl;

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
