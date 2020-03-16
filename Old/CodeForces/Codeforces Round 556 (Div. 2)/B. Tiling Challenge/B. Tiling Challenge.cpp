// B. Tiling Challenge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

const int N = 55;
string mp[N];
int n;

int mm[5][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0} };

void print() {
	for (int i = 0; i < n; i++)
		cout << mp[i] << endl;
	cout << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> mp[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
			else if (mp[i][j] == '.') {
				bool ok = true;
				for (int k = 0; k < 5; k++) {
					int ni = i + mm[k][0], nj = j + mm[k][1];
					if (mp[ni][nj] == '#') { ok = false; break; }
				}
				if (!ok) continue;
				for (int k = 0; k < 5; k++)
					mp[i + mm[k][0]][j + mm[k][1]] = '#';
				//cout << i << " " << j << endl;
			}

	
	bool ok = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (mp[i][j] == '.') 
			ok = false;
	cout << (ok ? "YES" : "NO") << endl;
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
