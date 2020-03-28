#include <iostream>
using namespace std;

int rec[10], rows[10], cols[10];
int num[512], cnt[512];
char map[9][9];

inline int getRecIdx(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}

inline void flip(int x, int y, int k) {
    rows[x] ^= 1 << k;
    cols[y] ^= 1 << k;
    rec[getRecIdx(x, y)] ^= 1 << k;
}

bool dfs(int cur) {
    if (cur == 0) return true;

    int temp = 10, x, y;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (map[i][j] == '.') {
                int v = rows[i] & cols[j] & rec[getRecIdx(i, j)];
                if (cnt[v] < temp)
                    x = i, y = j, temp = cnt[v];
            }
    int val = rows[x] & cols[y] & rec[getRecIdx(x, y)];
    for (; val; val -= val&-val) {
        int k = num[val&-val];
        flip(x, y, k);
        map[x][y] = '1' + k;
        if (dfs(cur - 1)) return true;
        flip(x, y, k);
    }
    map[x][y] = '.';
    return false;
}

int main() {
    for (int i = 0; i < 1 << 9; i++)
        for (int j = i; j; j -= j & -j)
            cnt[i]++;
    for (int i = 0; i < 9; i++)
        num[1 << i] = i;

    char str[100];
    while (~scanf("%s", str) && str[0] != 'e') {
        for (int i = 0; i < 9; i++)
            rows[i] = cols[i] = rec[i] = (1 << 9) - 1;
        int num = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                map[i][j] = str[i * 9 + j];
                if (map[i][j] != '.')
                    flip(i, j, map[i][j] - '1');
                else
                    num++;
            }
        if (dfs(num)) {
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    cout << map[i][j];
        }
        cout << endl;
    }
}