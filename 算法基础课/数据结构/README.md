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

```c++
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int stk[N], tt;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        
        while (tt > 0 && stk[tt] >= tmp) tt--;
        if (tt) ans.push_back(stk[tt]);
        else ans.push_back(-1);
        
        stk[++tt] = tmp;
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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





## KMP



