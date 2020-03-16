// 排座椅.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <vector>
#include <functional>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int cnt, idx;
	friend bool operator< (const Node& a, const Node& b) {
		return a.cnt < b.cnt;
	}
};

int main() {
	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	vector<Node> a(m + 1), b(n + 1);
	for (int i = 1; i <= m; i++)
		a[i].idx = i;
	for (int i = 1; i <= n; i++)
		b[i].idx = i;
	while (d--) {
		int xi, yj, p, q;
		cin >> xi >> yj >> p >> q;
		if (xi != p) {
			xi = min(xi, p);
			a[xi].cnt++;
		}
		else if (yj != q) {
			yj = min(yj, q);
			b[yj].cnt++;
		}
	}

	vector<int> ans;
	sort(a.begin(), a.end());
	for (int i = 0, j = a.size() - 1; i < k; i++, j--)
		ans.push_back(a[j].idx);
	sort(ans.begin(), ans.end());
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << " " << ans[i];
	cout << endl;
	sort(b.begin(), b.end());
	ans.clear();
	for (int i = 0, j = b.size() - 1; i < l; i++, j--)
		ans.push_back(b[j].idx);
	sort(ans.begin(), ans.end());
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << " " << ans[i];
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
