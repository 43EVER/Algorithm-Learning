// 选数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>primes{ 2, 3 };

bool is_prime(int n) {
	for (int i = 0; primes[i] <= sqrt(n); i++)
		if (n % primes[i] == 0)
			return false;
	return true;
}

vector<int> a;
int ans = 0, n, k, s = 0;

void dfs(int i, int len, int s) {
	for (int j = i + 1; j < a.size(); j++) {
		dfs(j, len + 1, s + a[j]);
	}
	if (len == k) {
		if (is_prime(s))
			ans++;
	}
}

int main() {
	for (int i = 5; i <= 10000 + 5; i++) {
		bool is = true;
		for (int j = 0; primes[j] <= sqrt(i); j++)
			if (i % primes[j] == 0) {
				is = false;
				break;
			}
		if (is)
			primes.push_back(i);
	}

	cin >> n >> k;
	a = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> a[i], s += a[i];
	dfs(-1, 0, 0);
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
