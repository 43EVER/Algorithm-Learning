// B. Neko Performs Cat Furrier Transform.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <bitset>
using namespace std;

int find_last_0(int x) {
	bitset<31>b = x;
	int i = 30;
	for (; i >= 0 && b[i] == 0; i--);
	for (; i >= 0 && b[i] == 1; i--);
	if (i == -1)
		return 0x3f3f3f3f;
	return i + 1;
}

int find_last_1(int x) {
	int ans = 0, pos = 1;
	while (x) {
		if (x & 1)
			ans = pos;
		x >>= 1;
		pos++;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	vector<int> vec;
	int ans = 1;
	while (find_last_1(x) > find_last_0(x)) {
		if (ans % 2) {
			int pos_0 = find_last_0(x);
			//cout << pos_0 << endl;
			x ^= (1 << pos_0) - 1;
			ans++;
			vec.push_back(pos_0);
		}
		else {
			x += 1;
			ans++;
		}
	}
	ans -= 1;
	cout << ans << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
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
