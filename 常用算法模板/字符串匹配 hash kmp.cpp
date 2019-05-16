#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL;

void kmp(const string & text, const string & pat) {
    int *next = new int[pat.size() + 1];
    bool ok = false;

    next[0] = next[1] = 0;
    for (int i = 1, j = 0; i < pat.size(); i++) {
        while (j && pat[i] != pat[j]) j = next[j];
        if (pat[i] == pat[j]) ++j;
        next[i + 1] = j;
    }
    
    for (int i = 0, j = 0; i < text.size(); i++) {
        while (j && text[i] != pat[j]) j = next[j];
        if (text[i] == pat[j]) ++j;
        if (j == pat.size()) {
            cout << i - j + 1 << " ";
            j = next[j];
            ok = true;
        }
    }
    if (!ok)    cout << -1;
    cout << endl;
}

ULL *power, *text_hash, base = 131;

void init(const string & text) {
    power = new ULL[text.size() + 1];
    text_hash = new ULL[text.size() + 1];
    power[0] = 1;
    text_hash[0] = 0;
    for (int i = 1; i <= text.size(); i++) {
        power[i] = power[i - 1] * 131;
        text_hash[i] = text_hash[i - 1] * 131 + text[i - 1] - 'a' + 1;
    }
}

ULL get_hash(int l, int r) {
    l++, r++;
    return text_hash[r] - text_hash[l - 1] * power[r - l + 1];
}

void hash_match(const string & text, const string & pat) {
    ULL pat_hash = pat[0] - 'a' + 1;
    init(text);
    bool ok = false;
    for (int i = 1; i < pat.size(); i++)
        pat_hash = pat_hash * 131 + pat[i] - 'a' + 1;
    
    for (int i = 0, j = pat.size() - 1; j < text.size(); i++, j++) {
        if (get_hash(i, j) == pat_hash) {
            ok = true;
            cout << i << " ";
        }
    }
    if (!ok)    cout << -1;
    cout << endl;
}

int main() {
    string text, pat;
    while (cin >> text >> pat) {
        hash_match(text, pat);
        kmp(text, pat);
    }
}