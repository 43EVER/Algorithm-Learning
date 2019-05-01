// POJ3614 Sunscreen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Cow {
	int minSPF, maxSPF;
	
	friend bool operator< (const Cow& a, const Cow& b) {
		return b.minSPF < a.minSPF;
	}
};

struct Loation {
	int idx, cnt;
	
	friend bool operator< (const Loation& a, const Loation& b) {
		return a.idx < b.idx;
	}
};

int main() {
	int c, l;
	cin >> c >> l;
	vector<Cow> a(c);
	for (int i = 0; i < c; i++) cin >> a[i].minSPF >> a[i].maxSPF;
	vector<Loation> b(l);
	for (int i = 0; i < l; i++) cin >> b[i].idx >> b[i].cnt;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = 0;
	for (int i = 0; i < c; i++) {
		int curmin = a[i].minSPF, curmax = a[i].maxSPF;
		int idx = -1;
		for (int j = 0; j < l; j++)
			if (b[j].cnt > 0 && b[j].idx >= curmin && b[j].idx <= curmax) idx = j;
		if (idx != -1)
			ans++, b[idx].cnt--;
	}

	cout << ans << endl;
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
