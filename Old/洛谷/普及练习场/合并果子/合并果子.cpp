// 合并果子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
using namespace std;

vector<long long>a(10000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long ans = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	make_heap(a.begin(), a.begin() + n, [](int a, int b) {return b < a; });
	for (int i = 1; i < n; i++) {
		long long int tmp = a[0];
		pop_heap(a.begin(), a.begin() + n - i + 1, [](int a, int b) {return b < a; });
		tmp += a[0];
		pop_heap(a.begin(), a.begin() + n - i, [](int a, int b) {return b < a; });
		ans += tmp;
		a[n - i - 1] = tmp;
		push_heap(a.begin(), a.begin() + n - i, [](int a, int b) {return b < a; });
	}
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
