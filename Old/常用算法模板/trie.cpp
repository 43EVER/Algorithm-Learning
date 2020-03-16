#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const int SIZE = 1e5;
int trie[SIZE][26], tot = 1;
bool end[SIZE];

void insert(const std::string & str) {
    int len = str.size(), p = 1;
    for (int k = 0; k < len; k++) {
        int ch = str[k] - 'a';
        if (trie[p][ch] == 0) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    end[p] = true;
}

bool search(const std::string & str) {
    int len = str.size(), p = 1;
    for (int k = 0; k < len; k++) {
        p = trie[p][str[k] - 'a'];
        if (p == 0) return false;
    }
    return end[p];
}

int main() {
    int m, n;
    std::string str1;
    while (std::cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            std::cin >> str1;
            insert(str1);
        }
        for (int i = 0; i < n; i++) {
            std::cin >> str1;
            std::cout << search(str1) << std::endl;
        }

        for (int i = 1; i <= tot; i++) {
            for (int j = 0; j < 26; j++)
                std::cout << trie[i][j] << " ";
            std::cout << std::endl;
        }
    }
    return 0;
}