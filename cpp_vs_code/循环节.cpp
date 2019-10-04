#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
char str[N];
int nxt[N];

void getNext() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && str[i] != str[j + 1]) j = nxt[j];
        if (str[i] == str[j + 1]) j++;
        nxt[i] = j;
    }
}

int main() {
    int T = 1;
    while (cin >> n) {
        scanf("%s", str + 1);
        getNext();
    
        cout << "Test case #" << T++ << endl;
        for (int i = 2; i <= n; i++) {
            int len = i - nxt[i];
            if (len != i && i % len == 0)
                cout << i << " " << i/len << endl;
        }
    }
}