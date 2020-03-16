// POJ2965 The Pilots Brothers' refrigerator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

int mp[4];

void flip(int i, int j) {
	int temp = (1 << 4) - 1;
	mp[i] ^= temp;
	temp = 1 << j;
	for (int k = 0; k < 4; k++)
		if (k != i) mp[k] ^= temp;
}

int countyi(int num) {
	int ans = 0;
	while (num) {
		if (num & 1) ++ans;
		num >>= 1;
	}
	return ans;
}

int ansFlips = (1 << 16) - 1, flips;

void dfs(int pos) {
	if (countyi(flips) >= countyi(ansFlips)) return;
	if (pos == 16) {
		if (mp[0] == 0 && mp[1] == 0 && mp[2] == 0 && mp[3] == 0) ansFlips = flips;
		return;
	}
	dfs(pos + 1);
	flips ^= 1 << pos;
	int i = pos >>2, j = pos % 4;
	flip(i, j);
	dfs(pos + 1);
	flips ^= 1 << pos;
	flip(i, j);
}

int main() {
	char ch;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			cin >> ch;
			if (ch == '+') mp[i] ^= (1 << j);
		}
	dfs(0);
	cout << countyi(ansFlips) << endl;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (((ansFlips >> (i * 4)) >> j) & 1)
				cout << i + 1 << " " << j + 1 << endl;
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
