## 链表与邻接表

#### 单链表：邻接表（存储图和树）

###### 算法模板

```c++
void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

void add(int k, int x) {
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}
```



#### 双链表：优化某些问题

###### 算法模板

```c++
void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add_to_head(int x) {
    e[idx] = x;
    l[idx] = 0;
    r[idx] = r[0];
    r[0] = idx++;
}

void add_to_back(int x) {
    e[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    l[1] = idx++;
}

void addR(int k, int x) {
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx++;
}

void addL(int k, int x) {
    e[idx] = x;
    l[idx] = l[k];
    r[idx] = k;
    r[l[k]] = idx;
    l[k] = idx++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}	
```





## 栈与队列

#### 栈模板

```c++
int stk[N], tt;

void push(int x) {
	stk[++tt] = x;    
}

void pop() {
    --tt;
}

bool empty() {
    return tt > 0;
}

int top() {
    return stk[tt];
}
```



#### 单调栈

给定一个序列，求每一个数的左边，离他最近的满足某种性质的数的位置



这里是找离他最近的并且 自己 大于他的位置

```c++
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N], tt;

int main() {
    int n, x;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        
        while (tt > 0 && stk[tt] >= x) tt--;
        if (tt) cout << stk[tt] << ' ';
        else cout << "-1 ";
        
        stk[++tt] = x;
    }
}
```





#### 队列模板

```c++
int q[N], hh, tt = -1;

void push(int x) {
    q[++tt] = x;
}

void pop() {
    hh++;
}

bool empty() {
    return hh <= tt;
}

int front() {
    return q[hh];
}

int back() {
    return q[tt];
}
```



#### 单调队列

求滑动窗口里的最值

```c++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int q[N], tt = - 1, hh;
int a[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - q[hh] >= k) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = a[i];
        if (i >= k - 1) cout <<  q[hh] << " ";
    }
    cout << endl;
    tt = -1, hh = 0;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - q[hh] >= k) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = a[i];
        if (i >= k - 1) cout << q[hh] << " ";
    }
}
```





## KMP

#### 朴素做法

```c++
int find(const string & s, const string & p) {
    int n = s.size(), m = p.size();
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= m; j++)
            if (s[i + j - 1] != p[j]) {
                flag = flase;
                break;
            }
        if (flag) return i;
    }
    return -1;
}
```



#### 算法模板

```c++
for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == [j + 1]) j++;
    ne[i] = j;
}

for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m) return i - m + 1;
}
```



## Trie 树

###### 作用：高效存储和查找字符串集合

###### 注意： 空间开大点

#### 数据结构模板

```c++
int son[N][26], cnt[N], idx;

void insert(const string & str) {
    int p = 0;
    for (char ch : str) {
        if (!son[p][ch - 'a']) son[p][ch - 'a'] = ++idx;
        p = son[p][ch - 'a'];
    }
    cnt[p]++;
}

int query(const string & str) {
    int p = 0;
    for (char ch : str) {
        if (!son[p][ch - 'a']) return 0;
    	p = son[p][ch - 'a'];
    }
    return cnt[p];
}
```



## 并查集

#### 数据结构模板

```c++
int p[N];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

void join(int x, int y) {
    p[find(x)] = find(y);
}
```



## 堆

#### 功能

1. 插入一个数
2. 求集合中的最小值
3. 删除最小值
4. 删除任意一个元素
5. 修改任意一个元素



#### 性质

根节点 小于等于 子树的全部点（递归定义）



#### 模板

```c++
int h[N], sz;

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return x * 2 + 1;
}

void down(int u) {
    int t = u;
    if (lc(u) <= sz && h[lc(u)] < h[t]) t = lc(u);
    if (rc(u) <= sz && h[rc(u)] < h[t]) t = rc(u);
    if (u != t) swap(h[u], h[t]), down(t);
}
```



## 哈希表

#### 处理碰撞

###### 拉链法（红黑树）

```c++
#include <iostream>
#include <set>
using namespace std;

const int N = 1e5 + 7;

set<int> h[N];

inline int hash_(int x) {
    int pos = ((x % N) + N) % N;
    return pos;
}

inline void insert(int x) {
    h[hash_(x)].insert(x);
}

inline bool query(int x) {
    return h[hash_(x)].count(x);
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'I') insert(x);
        else cout << (query(x) ? "Yes" : "No") << endl;
    }
}
```

###### 拉链法（链表）

```c++
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 3;

int h[N], e[N], ne[N], idx;

inline int hash_(int x) {
    return ((x % N) + N) % N;
}

void insert(int x) {
    int k = hash_(x);
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool query(int x) {
    int k = hash_(x);
    for (int i = h[k]; i != -1; i = ne[i]) if (e[i] == x) return true;
    return false;
}

int main() {
    int n, x;
    char op;
    cin >> n;
    
    memset(h, -1, sizeof(h));
    
    while (n--) {
        cin >> op >> x;
        if (op == 'I') insert(x);
        else cout << (query(x) ? "Yes" : "No") << endl;
    }
}
```





###### 开放寻址法

```c++
#include <iostream>
#include <cstring>
using namespace std;

const int N = 3e5 + 7;
const int INF = 0x3f3f3f3f;

int h[N];

int hash_(int x) {
    return ((x % N) + N) % N;
}

int find(int x) {
    int k = hash_(x);
    while (h[k] != INF && h[k] != x) {
        k++;
        if (k == N) k -= N;
    }
    return k;
}

void insert(int x) {
    int pos = find(x);
    h[pos] = x;
}

bool query(int x) {
    int pos = find(x);
    return h[pos] != INF;
}

int main() {
    memset(h, 0x3f, sizeof h);
    
    int n, x;
    char op;
    cin >> n;
    while (n--) {
        cin >> op >> x;
        if (op == 'I') insert(x);
        else cout << (query(x) ? "Yes" : "No") << endl;
    }
}
```



## 字符串哈希

#### 算法原理

字符串前缀映射成 P 进制数

不能把某个字母映射成0，会导致 "A" == "AA"



#### 算法模板

```c++
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ull;
const int N = 1e5 + 10;

ull h[N], p[N];

ull get_hash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1]; 
}

int main() {
    string str;
    int n, m;
    cin >> n >> m >> str;
    p[0] = 1;
    for (int i = 1; i <= str.size(); i++) {
        p[i] = p[i - 1] * 131;
        h[i] = h[i - 1] * 131 + (str[i - 1] - 'A' + 1);
    }
    
    int l1, r1, l2, r2;
    while (m--) {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (get_hash(l1, r1) == get_hash(l2, r2) ? "Yes" : "No") << endl;
    }
}
```



## STL

#### vector（支持比较运算，字典序）

#### pair（支持比较运算，字典序）

#### string

#### queue

q.back(), q.front()

没有 clear

#### priority_queue

小根堆可以插入负数

没有 clear

#### stack

没有 clear

#### deque

慢一点

#### set/multiset，map,multimap

erase(x) 删除 x

erase(it) 删除迭代器

lower_bound(x) 返回第一个 >= x 的 迭代器

upper_bound(x) 返回第一个 > x 的 迭代器



####  unordered_set, unordered_map, unordered_multiset, unordered_multimap

所有操作基本都是 $O(1)$，但不能用 lower_bound 和 upper_bound，内部无序



#### bitset

~ & | ^

左移，右移

== !=

[]

count() 多少个1

any() 是否有1

set() 全为一

set(k, v) 把第 k 个位置设成 v

reset() 全为0 