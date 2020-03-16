// 费解的开关.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

bitset<5> mat[5], tmpmat[5];
int mm[5][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {0, 0} };

inline void flip(int ci, int cj) {
	for (int i = 0; i < 5; i++) {
		int ni = ci + mm[i][0];
		int nj = cj + mm[i][1];
		if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5)
			mat[ni].flip(nj);
	}
}

inline int judge(int x) {
	int cnt = 0;
	bitset<5> flips(x), tmp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) if (!flips[j])
			flip(i, j), cnt++;
		flips = mat[i];
	}
	if (flips.count() == 5)
		return cnt;
	return -1;
}

int ans;

void dfs(int x, int pos) {
	if (pos == 5) {
		int tmp = judge(x);
		if (tmp != -1)
			ans = min(ans, tmp);
		memcpy(mat, tmpmat, sizeof(mat));
		return;
	}
	dfs(x, pos + 1);
	x = (1 << pos) | x;
	dfs(x, pos + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int t;
	string tmp;
	cin >> t;
	while (t--) {
		ans = 0x3f3f3f3f;
		for (int i = 0; i < 5; i++) {
			cin >> tmp;
			mat[i] = bitset<5>(tmp);
		}
		memcpy(tmpmat, mat, sizeof(mat));
		dfs(0, 0);
		if (ans > 6)
			ans = -1;
		cout << ans << endl;
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
