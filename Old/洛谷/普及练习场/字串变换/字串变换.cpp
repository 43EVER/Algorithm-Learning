// 字串变换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;

multimap<string, string> m1, m2;
string source, ans;
map<string, int> a;

struct Node {
	string str;
	int cnt;

	friend bool operator< (const Node& a, const Node& b) {
		return b.cnt < a.cnt;
	}
};

int bfs1() {
	priority_queue<Node> q;
	q.push({ source, 0 });
	int cnt = 0;
	a[source] = 0;
	while (!q.empty() && cnt <= 5) {
		Node cur = q.top(); q.pop();
		if (cur.str == ans)
			return cur.cnt;
		auto it = m1.begin();
		while (it != m1.end()) {
			size_t pos = cur.str.find(it->first);
			while (pos != cur.str.npos) {
				string tmp = cur.str;
				tmp.replace(pos, it->first.length(), it->second);
				if (a.find(tmp) != a.end()) {
					pos = cur.str.find(it->first, pos + 1);
					continue;
				}
				pos = cur.str.find(it->first, pos + 1);
				cnt = cur.cnt + 1;
				q.push({ tmp, cur.cnt + 1 });
				a[tmp] = cur.cnt + 1;
			}
			it++;
		}
	}
	return -1;
}

int bfs2() {
	priority_queue<Node> q;
	q.push({ ans, 0 });
	int cnt = 0;
	while (!q.empty() && cnt <= 5) {
		Node cur = q.top(); q.pop();
		if (a.find(cur.str) != a.end())
			return cur.cnt + a[cur.str];
		auto it = m2.begin();
		while (it != m2.end()) {
			size_t pos = cur.str.find(it->first);
			while (pos != cur.str.npos) {
				string tmp = cur.str;
				tmp.replace(pos, it->first.length(), it->second);
				if (a.find(tmp) != a.end())
					return cur.cnt + 1 + a[tmp];
				pos = cur.str.find(it->first, pos + 1);
				q.push({ tmp, cur.cnt + 1 });
				cnt = cur.cnt + 1;
			}
			it++;
		}
	}
	return -1;
}

int main() {
	string tmp1, tmp2;
	cin >> source >> ans;
	while (cin >> tmp1 >> tmp2)
		m1.insert({ tmp1, tmp2 }), m2.insert({ tmp2, tmp1 });
	int t = bfs1();
	if (t == -1)
		t = bfs2();
	if (t == -1)
		cout << "NO ANSWER!" << endl;
	else
		cout << t << endl;
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
