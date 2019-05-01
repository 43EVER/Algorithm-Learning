// C. Prefix Sum Primes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

vector<int> primes({ 2, 3, 5 });
int ans[N];

void init() {
	for (int i = 6; i <= 200005 * 2; i++) {
		bool ok = true;
		for (int j = 0; primes[j] * primes[j] <= i; j++)
			if (i % primes[j] == 0) {
				ok = false;
				break;
			}
		if (ok) primes.push_back(i);
	}
}

int main() {
	init();
	int n, yi = 0, er = 0, x, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x == 1) yi++;
		else er++;
		sum += x;
	}
	//cout << yi << " " << er << " " << sum << endl;
	int cur = 0, cnt = 0, delta, pos = 0;
	while (primes[cnt] <= sum) {
		delta = primes[cnt] - cur;
		while (delta > 1 && er) {
			--er;
			delta -= 2;
			cur += 2;
			ans[pos++] = 2;
		}
		while (delta > 0 && yi) {
			--yi;
			delta -= 1;
			cur += 1;
			ans[pos++] = 1;
		}
		cnt++;
		//cout << primes[cnt] << " " << sum << endl;
	}
	while (er--)
		ans[pos++] = 2;
	while (yi--)
		ans[pos++] = 1;
	for (int i = 0; i < pos; i++)
		cout << ans[i] << " ";
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
