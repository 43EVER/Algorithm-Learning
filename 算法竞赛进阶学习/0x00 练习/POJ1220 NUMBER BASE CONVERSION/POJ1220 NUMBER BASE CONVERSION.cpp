#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<char, int> c2i;
map<int, char> i2c;

bool less_than(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	return a < b;
}

string add(const string & a, const string & b, int base = 10) {
	string res;
	int i = 0, j = 0, tmp = 0;
	while (i < a.length() && j < b.length()) {
		tmp += c2i[a[i++]] + c2i[b[j++]];
		res.push_back(i2c[tmp % base]);
		tmp /= base;
	}
	while (i < a.length()) {
		tmp += c2i[a[i++]];
		res.push_back(i2c[tmp % base]);
		tmp /= base;
	}
	while (j < b.length()) {
		tmp += c2i[b[j++]];
		res.push_back(i2c[tmp % base]);
		tmp /= base;
	}
	while (tmp) {
		res.push_back(i2c[tmp % base]);
		tmp /= base;
	}
	return res;
}

string multiply(const string & a, int b, int base = 10) {
	long long tmp = 0;
	string res;
	for (int i = 0; i < a.length(); i++) {
		tmp += c2i[a[i]] * b;
		res.push_back(i2c[tmp % base]);
		tmp /= base;
	}
	while (tmp) {
		res.push_back(i2c[tmp % base]);
		tmp /= base;
	}
	return res;
}

string trans(string x, int base1, int base2) {
	reverse(x.begin(), x.end());
	string pow = "1", res = "0";
	for (int i = 0; i < x.length(); i++) {
		string tmp = multiply(pow, c2i[x[i]], base2);
		res = add(res, tmp, base2);
		pow = multiply(pow, base1, base2);
		//cout << endl << pow << " " << c2i[x[i]] << " " << x[i] << " " << endl << endl;
	}
	return res;
}

int main() {
	int cnt = 0, t;
	for (int i = 0; i < 10; i++) c2i['0' + i] = cnt, i2c[cnt++] = '0' + i;
	for (int i = 0; i < 26; i++) c2i['A' + i] = cnt, i2c[cnt++] = 'A' + i;
	for (int i = 0; i < 26; i++) c2i['a' + i] = cnt, i2c[cnt++] = 'a' + i;

	cin >> t;
	while (t--) {
		string a, res;
		int base1, base2;
		cin >> base1 >> base2 >> a;
		res = trans(a, base1, base2);
		reverse(res.begin(), res.end());

		cout << base1 << " " << a << endl;
		cout << base2 << " " << res << endl << endl;
	}
}