#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;



int main() {
    string str1;
    while (cin >> str1) {
        int len = str1.size();
        str1 += str1;
        int i = 0, j = 1, k;

        while (i < len && j < len) {
            for (k = 0; k < len && str1[i + k] == str1[j + k]; ++k);
            if (k == len) break;
            if (str1[i + k] < str1[j + k]) {
                j += k + 1;
                if (i == j) j += 1;
            }
            else {
                i += k + 1;
                if (i == j) i += 1;
            }
        }
        cout << min(i, j) + 1 << endl;
    }
    return 0;
}