// 马的遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstring>
using namespace std;

struct Node {
	int i, j, cnt;
};

int mp[400 + 5][400 + 5];
int n, m;

int mm[8][2] = {
	{2, 1}, {1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-1, -2}, {-2, -1}
};

void bfs(int si, int sj) {
	queue<Node> q;
	Node next;
	q.push({ si, sj, 0 });
	mp[si][sj] = 0;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			next.i = cur.i + mm[i][0];
			next.j = cur.j + mm[i][1];
			next.cnt = cur.cnt + 1;
			if (next.i < 0 || next.i >= n || next.j < 0 || next.j >= m || mp[next.i][next.j] != -1)
				continue;
			q.push(next);
			mp[next.i][next.j] = next.cnt;
		}
	}
}

int main() {
	memset(mp, -1, sizeof(mp));
	cin >> n >> m;
	int si, sj;
	cin >> si >> sj;
	bfs(si - 1, sj - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setw(5) <<  std::left << mp[i][j];
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
