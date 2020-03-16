// POJ1328 Radar Installation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct Range {
	double from, to;
	friend bool operator< (const Range& a, const Range& b) {
		return a.from < b.from;
	}
} Lines[1000 + 5];

int main() {
	int caseNum = 0, islandNum, r, x, y;
	double tempPoint;
	while (cin >> islandNum >> r) {
		if (!islandNum && !r) break;
		bool ok = true;
		for (int i = 0; i < islandNum; i++) {
			cin >> x >> y;
			if (!ok) continue;
			if (abs(y) > r) { ok = false; continue; }
			tempPoint = sqrt((double)r * r - y * y);
			Lines[i].from = x - tempPoint, Lines[i].to = x + tempPoint;
		}
		int radar = 0;
		if (!ok) radar = -1;
		else {
			sort(Lines, Lines + islandNum);
			radar = 1;
			tempPoint = Lines[0].to;
			for (int i = 1; i < islandNum; i++)
				if (tempPoint < Lines[i].from)
					radar++, tempPoint = Lines[i].to;
				else
					tempPoint = min(tempPoint, Lines[i].to);
		}
		cout << "Case " << ++caseNum << ": " << radar << endl;
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
