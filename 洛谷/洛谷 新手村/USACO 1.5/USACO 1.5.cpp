// USACO 1.5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

vector<int> primes;
int a, b;

bool check_prime(int n) {
	for (int i = 0; primes[i] <= sqrt(n); i++)
		if (n % primes[i] == 0)
			return false;
	if (n >= a && n <= b)
		return true;
	return false;
}

int main() {
	primes = vector<int>{ 2, 3 };
	for (int i = 5; i <= 100000; i++) {
		bool isprime = true;
		for (int j = 1; primes[j] <= sqrt(i); j++)
			if (i % primes[j] == 0) {
				isprime = false;
				break;
			}
		if (isprime)
			primes.push_back(i);
	}
	cin >> a >> b;

	for (int i = 2; i <= 11; i++)
		if (check_prime(i))
			cout << i << endl;

	set<int> s;
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			int sum = i * 101 + j * 10;
			if (check_prime(sum))
				s.insert(sum);
			for (int k = 0; k < 10; k++) {
				int sum = i * 10001 + j * 1010 + k * 100;
				if (check_prime(sum))
					s.insert(sum);
				for (int l = 0; l < 10; l++) {
					int sum = i * 1000001 + j * 100010 + k * 10100 + l * 1000;
					if (check_prime(sum))
						s.insert(sum);
				}
			}
		}

	auto it = s.begin();
	while (it != s.end())
		cout << *(it++) << endl;
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
