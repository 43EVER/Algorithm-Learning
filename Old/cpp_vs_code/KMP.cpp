#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getNext(const char * pat, int len) {
    vector<int> Next(len + 1);
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && pat[i] != pat[j + 1]) j = Next[j];
        if (pat[i] == pat[j + 1]) j++;
        Next[i] = j;
    }

    return Next;
}

vector<int> kmpMatch(const char * txt, const char * pat, const vector<int> & Next) {
    int txt_len = strlen(txt + 1);
    int pat_len = strlen(pat + 1);
    vector<int> f(txt_len + 1);

    for (int i = 1, j = 0; i <= txt_len; i++) {
        while (j && txt[i] != pat[j + 1] || j == pat_len) j = Next[j];
        if (txt[i] == pat[j + 1]) j++;
        f[i] = j;
    }

    return f;
}

int main() {
    char txt[1000], pat[1000];
    while (cin >> (txt + 1) >> (pat + 1)) {
        auto Next = getNext(pat, strlen(pat + 1));
        auto res = kmpMatch(txt, pat, Next);
        for (int i = 1; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}