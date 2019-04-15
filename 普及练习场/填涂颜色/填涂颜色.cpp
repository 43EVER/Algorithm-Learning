// 填涂颜色.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maps[30 + 5][30 + 5];
int mm[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int n;

void bfs(int si, int sj) {
	queue< pair<int, int> > q;
	q.push({ si, sj });
	maps[si][sj] = 3;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { cur.first + mm[i][0], cur.second + mm[i][1] };
			if (next.first >= 0 && next.first <= n + 1 && next.second >= 0 && next.second <= n + 1 && maps[next.first][next.second] == 0)
				q.push(next), maps[next.first][next.second] = 3;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> maps[i][j];

	bfs(0, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (maps[i][j] == 3)
				cout << "0 ";
			else if (maps[i][j] == 0)
				cout << "2 ";
			else
				cout << "1 ";
		cout << endl;
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
