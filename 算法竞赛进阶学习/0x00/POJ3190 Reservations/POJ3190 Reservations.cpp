// POJ3190 Reservations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int from, to, idx;
	friend bool operator< (const Node& a, const Node& b) {
		return a.from < b.from;
	}
};

struct Node2 {
	int cnt, idx;
	friend bool operator< (const Node2& a, const Node2& b) {
		return b.cnt < a.cnt;
	}
};

const int N = 50000 + 5;
Node a[N];
int ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].from >> a[i].to, a[i].idx = i;
	sort(a + 1, a + n + 1);

	int min_value = 0x3f3f3f3f, cnt = 1, idx;
	priority_queue<Node2> q;
	for (int i = 1; i <= n; i++) {
		if (q.empty() || a[i].from <= q.top().cnt) {
			ans[a[i].idx] = cnt;
			q.push({ a[i].to, cnt++ });
		}
		else {
			idx = q.top().idx;
			q.pop();
			q.push({ a[i].to, idx });
			ans[a[i].idx] = idx;
		}
	}

	cout << cnt - 1 << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
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
