// 国王游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct BigNum {
	string num;
	
	BigNum(const string& str) {
		num = str;
		reverse(num.begin(), num.end());
	}

	BigNum operator* (int x) {
		BigNum big("");
		int tmp = 0;
		for (int i = 0; i < num.length(); i++) {
			tmp += (num[i] - '0') * x;
			big.num.push_back(tmp % 10 + '0');
			tmp /= 10;
		}
		while (tmp) {
			big.num.push_back(tmp % 10 + '0');
			tmp /= 10;
		}
		return big;
	}

	bool operator< (BigNum big) {
		if (num.length() != big.num.length())
			return num.length() < big.num.length();
		string tmp = num;
		string tmp1 = big.num;
		reverse(tmp1.begin(), tmp1.end());
		reverse(tmp.begin(), tmp.end());
		return tmp < tmp1;
	}

	friend ostream& operator<< (ostream& os, BigNum big) {
		reverse(big.num.begin(), big.num.end());
		os << big.num;
		return os;
	}

	BigNum operator/ (int x) {
		BigNum big("");
		int tmp = 0, pos = 0;
		for (int i = num.length() - 1; i >= 0; i--) {
			tmp = tmp * 10 + num[i] - '0';
			big.num.push_back(tmp / x + '0');
			tmp %= x;
		}
		for (; pos < big.num.length() - 1 && big.num[pos] == '0'; pos++);
		big.num = big.num.substr(pos, big.num.length() - pos);
		reverse(big.num.begin(), big.num.end());
		return big;
	}
};

struct Node {
	int left, right;
};

Node a[10000 + 10];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i].left >> a[i].right;
	}

	sort(a + 1, a + n + 1, [](Node & a, Node & b) {
		return a.left* a.right < b.left* b.right;
		});

	BigNum tmp("1");
	BigNum ans("0");

	for (int i = 1; i <= n; i++) {
		tmp = tmp * a[i - 1].left;
		BigNum res = tmp / a[i].right;
		if (ans < res)
			ans = res;
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
