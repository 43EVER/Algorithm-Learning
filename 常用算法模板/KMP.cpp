#include <iostream>
#include <iomanip>
using namespace std;

const int N = 1005;
char txt[N], pat[N];
int Next[N];

int main() {
    while (cin >> (txt + 1) >> (pat + 1)) {
        memset(Next, 0, sizeof(Next));
        int p_len = strlen(pat + 1);
        int t_len = strlen(txt + 1);
        for (int i = 2, j = 0; i <= p_len; i++) {
            while (j && pat[i] != pat[j + 1]) j = Next[j];
            if (pat[i] == pat[j + 1]) j++;
            Next[i] = j;
        }

        for (int i = 1, j = 0; i <= t_len; i++) {
            while (j && txt[i] != pat[j + 1] || j == p_len) j = Next[j];
            if (txt[i] == pat[j + 1]) j++;
            if (j == p_len)
                cout << "Match at " << i - j + 1 << endl;
        }
        cout << "Finished" << endl;
    }
}