#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

int v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	int a = 0, b = n - 1;
	int last = 0;
	string str;
	while (v[a] != v[b]) {
		if (v[a] > last && (v[a] < v[b] || v[b] <= last))
			str += 'L', last = v[a++];
		else if (v[b] > last && (v[b] < v[a] || v[a] <= last))
			str += 'R', last = v[b--];
		else break;
	}
	if (a == b) {
		if (v[a] > last)
			str += 'L';
	}
	else if (v[a] == v[b] && v[a] > last) {
		int x = 1, y = 1;
		while (v[a + x] > v[a + x - 1]) x++;
		while (v[b - y] > v[b - y + 1]) y++;

		if (x > y) for (int i = 0; i < x; i++)
			str += 'L';
		else for (int i = 0; i < y; i++)
			str += 'R';
	}

	cout << str.length() << endl;
	cout << str << endl;
}