#include <iostream>
using namespace std;

const int N = 10e5 + 5;
long long b[N], a[N];

int main() {
	long long n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) b[i] = 1;
	n -= (1 + k) * k >> 1;
	//cout << n << endl;
	b[1] += n / k;
	n -= n / k * k;
	a[1] = b[1];
	for (int i = 2; i <= k; i++)
		a[i] = b[i] + a[i - 1];
	while (n) {
		int pos = k - n + 1;
		if (a[pos] + 1 > a[pos - 1] * 2 && pos <= k) pos++;
		if (pos > k) break;
		n -= (k - pos) + 1;
		for (int i = pos; i <= k; i++) a[i]++;
	}
	bool ok = true;
	for (int i = 2; i <= k; i++)
		if (a[i] > a[i - 1] * 2 || a[i] == a[i - 1] || n) {
			ok = false;
			break;
		}
	if (ok) {
		cout << "YES" << endl;
		for (int i = 1; i <= k; i++)
			cout << a[i] << " ";
	}
	else
		cout << "NO" << endl;
}