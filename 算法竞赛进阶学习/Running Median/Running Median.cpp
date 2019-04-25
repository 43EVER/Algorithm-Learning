// Running Median.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;

void insert(int x) {
	if (q2.empty() || x > q2.top()) q2.push(x);
	else q1.push(x);

	if (q2.size() > q1.size() + 1) q1.push(q2.top()), q2.pop();
	if (q1.size() > q2.size() + 1) q2.push(q1.top()), q1.pop();
}

int get() {
	if (q1.size() > q2.size()) return q1.top();
	return q2.top();
}

void print(const vector<int> ans, int idx) {
	cout << idx << " " << ans.size() << endl;
	for (int i = 1; i <= ans.size(); i++) {
		cout << ans[i - 1] << " ";
		if (i % 10 == 0 || i == ans.size())
			cout << endl;
	}
}

int main() {
	int t, idx, len, tmp;
	cin >> t;
	while (t--) {
		cin >> idx >> len;
		q1 = priority_queue<int>();
		q2 = priority_queue<int, vector<int>, greater<int> >();
		vector<int> ans;
		for (int i = 1; i <= len; i++) {
			cin >> tmp;
			insert(tmp);
			if (i % 2) ans.push_back(get());
		}
		print(ans, idx);
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
