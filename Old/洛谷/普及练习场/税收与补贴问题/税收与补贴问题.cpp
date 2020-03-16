#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 10000;

vector<int> prices(MAX * 2 + 5);

int main() {
	int estprice, prim_price, prim_cnt, asc;
	int tmpprice, tmpcnt, lastprice = 0;
	cin >> estprice >> prim_price >> prim_cnt;
	prices[prim_price] = prim_cnt;
	lastprice = prim_price;
	while (cin >> tmpprice >> tmpcnt && tmpprice != -1) {
		prices[tmpprice] = tmpcnt;
		for (int i = lastprice + 1; i < tmpprice; i++)
			prices[i] = prices[i - 1] + (tmpcnt - prices[lastprice]) / (tmpprice - lastprice);
		lastprice = tmpprice;
	}
	cin >> asc;
	while (prices[lastprice] > 0)
		lastprice++, prices[lastprice] = prices[lastprice - 1] - asc;

	double minv = -0x3f3f3f3f, maxv = 0x3f3f3f3f;
	for (int i = prim_price; prices[i] > 0; i++) {
		int cofx = prices[estprice] - prices[i];
		int cofc = (i - prim_price) * prices[i] - (estprice - prim_price) * prices[estprice];
		double ans = 1.0 * cofc / cofx;
		if (cofx < 0)
			maxv = min(maxv, ans);
		else
			minv = max(minv, ans);
	}
	if (maxv - minv >= 1e-5) {
		if (minv > 0)
			cout << int(ceil(minv)) << endl;
		else if (maxv < 0)
			cout << int(floor(maxv)) << endl;
		else
			cout << 0 << endl;
	}
	else
		cout << "NO SOLUTION" << endl;
}