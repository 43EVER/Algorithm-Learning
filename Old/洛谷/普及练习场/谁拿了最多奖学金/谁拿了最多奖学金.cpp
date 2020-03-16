// 谁拿了最多奖学金.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Node {
	string name;
	int idx, money, score;
	bool isGb, isXb;
};

int main() {
	int n;
	cin >> n;
	
	int totalMoney = 0, highestMoney = 0;
	string highestName = "";

	int scorea, scoreb, paper, money;
	string name;
	char isGb, isXb;
	while (n--) {
		cin >> name >> scorea >> scoreb >> isGb >> isXb >> paper;
		money = 0;
		if (scorea > 80 && paper > 0)
			money += 8000;
		if (scorea > 85 && scoreb > 80)
			money += 4000;
		if (scorea > 90)
			money += 2000;
		if (scorea > 85 && isXb == 'Y')
			money += 1000;
		if (scoreb > 80 && isGb == 'Y')
			money += 850;

		totalMoney += money;

		if (money > highestMoney) {
			highestMoney = money;
			highestName = name;
		}
	}

	cout << highestName << endl << highestMoney << endl << totalMoney;
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
