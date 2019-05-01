#include <iostream>
#include <vector>
using namespace std;

vector<int> chosen;
int stack[100010], top, address, n, m;

void call(int ret_add, int x) {
	stack[++top] = ret_add;
	stack[++top] = x;
}

int ret() {
	int ret_add = stack[top - 1];
	top -= 2;
	return ret_add;
}

void calc(int x) {
	if (chosen.size() > m || n + 1 - x + chosen.size() < m)
		return;
	if (x == n + 1) {
		for (int i = 0; i < chosen.size(); i++)
			cout << chosen[i] << " ";
		cout << endl;
		return;
	}
	chosen.push_back(x);
	calc(x + 1);
	chosen.pop_back();
	calc(x + 1);
}

int main() {
	cin >> n >> m;
	call(0, 1);
	while (top) {
		int x = stack[top];
		switch (address) {
		case 0:
			if (chosen.size() > m || chosen.size() + n + 1 - x < m) {
				address = ret();
				continue;
			}
			if (x == n + 1) {
				for (int i = 0; i < chosen.size(); i++)
					cout << chosen[i] << " ";
				cout << endl;
				address = ret();
				continue;
			}
			chosen.push_back(x);
			call(1, x + 1);
			continue;
		case 1:
			chosen.pop_back();
			address = 0;
			call(ret(), x + 1);
		}
	}
}