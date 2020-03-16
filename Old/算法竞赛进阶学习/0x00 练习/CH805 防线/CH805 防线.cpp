#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
long long a[N], b[N], g[N];

int main() {
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i] >> g[i];
		long long l = 0, r = 1, inf = 1;
		r <<= 31, inf <<= 31;
		while (l < r) {
			long long m = (l + r) >> 1;
			long long tmp = 0;
			for (int i = 0; i < n; i++)
				if (a[i] <= m) tmp += (min(b[i], m) - a[i]) / g[i] + 1;
			if (tmp & 1) r = m;
			else l = m + 1;
		}
		if (l == inf)
			cout << "There's no weakness." << endl;
		else {
			int ans = 0;
			for (int i = 0; i < n; i++)
				if (l >= a[i] && l <= b[i] && (l - a[i]) % g[i] == 0) ++ans;
			cout << l << " " << ans << endl;
		}
	}
}