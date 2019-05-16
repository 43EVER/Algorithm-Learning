#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

const int N = 1e6 + 5;

int sum[N], max_v[N];
stack<int> before, after;

void solve(char op, int value) {
	int pos;
	switch (op) {
	case 'I':
		before.push(value);
		pos = before.size();
		sum[pos] = value + sum[pos - 1];
		max_v[pos] = max(max_v[pos - 1], sum[pos]);
		break;
	case 'D':
		before.pop();
		break;
	case 'L':
		if (!before.empty()) {
			after.push(before.top());
			before.pop();
		}
		break;
	case 'R':
		if (!after.empty()) {
			before.push(after.top());
			after.pop();
			pos = before.size();
			sum[pos] = sum[pos - 1] + before.top();
			max_v[pos] = max(max_v[pos - 1], sum[pos]);
		}
		break;
	case 'Q':
		pos = before.size();
		cout << max_v[value] << endl;
		break;
	default:
		break;
	}
}

int main() {
	int n, value;
	char op;

	while (EOF != scanf("%d", &n)) {
		before = stack<int>();
		after = stack<int>();
		max_v[0] = -0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			scanf(" %c", &op);
			if (op != 'L' && op != 'R' && op != 'D') scanf("%d", &value);
			solve(op, value);
		}
	}
}