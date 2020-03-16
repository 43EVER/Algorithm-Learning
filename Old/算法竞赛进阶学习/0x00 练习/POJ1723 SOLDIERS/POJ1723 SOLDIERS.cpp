// 数学问题 中位数 排序

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10005;
int ax[N], ay[N], n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ax[i] >> ay[i];

	int ans = 0, mid = 1 + n / 2;
	sort(ay + 1, ay + 1 + n);
	for (int i = 1; i <= n; i++) ans += abs(ay[i] - ay[mid]);
	sort(ax + 1, ax + 1 + n);
	for (int i = 1; i <= n; i++) ax[i] -= i;
	sort(ax + 1, ax + 1 + n);
	for (int i = 1; i <= n; i++) ans += abs(ax[i] - ax[mid]);

	cout << ans << endl;
}