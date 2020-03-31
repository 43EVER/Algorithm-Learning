## 快排（分治）

#### 算法流程

1. 确定分界点 x（a[l], a[r], a[mid], 随机）
2. **调整区间**（左边所有数 <= x，右边所有数 >= x）
   1. 浪费额外空间
      1. 开两个额外数组 b, c
      2. 扫描区间，对于 a[i] <= x，放进 b。a[i] >= x，放进 c
      3. 然后把 b 放进 a，再把 c 放进 a
   2. 优雅做法
      1. 两个指针 i，j，分别从两端开始，往中间走
      2. 如果 a[i] <= x i++，直到 a[i] >= x，i 停止（错位，应该放右边）
      3. 如果 a[j] >= x j--，知道 a[j] <= x，j 停止（错位，应该放左边）
      4. swap(a[i], a[j])
3. 递归处理左右两段

#### 模板

```c++
void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    
    int x = a[l + (rand() % (r - l + 1))];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}
```

* 模板里为什么不写 quick_sort(a, l, i)
  * 因为 i 出来的时候，指向的是一个 >= x 的数，所以得写
    * quick_sort(a, l, i - 1)
    * quick_sort(a, i, r)
  * x 不能取 a[l]，会死循环
    * 1 2，i = 1，j = 0
    * quick_sort(a, 0, -1); quick_sort(a, 0, 1);



## 归并排序（分治）

#### 算法流程

1. 确定分界点 mid = (l + r) / 2
2. 递归排序左边和右边
3. **归并**（合二为一）
   1. 两个指针 i j，只想两个序列的开头
   2. 两个指针 较小值放进 第二个数组，指针往后移
   3. 把序列剩下的部分放进第二个数组

#### 模板

```c++
void merge_sort(int a[], int l, int r, int c[]) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid, c), merge_sort(a, mid + 1, r, c);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++)
        if (a[i] <= a[j]) c[k] = a[i++];
    	else c[k] = a[j++];
   	for (int k = l; k <= r; k++) a[k] = c[k];
}
```



## 整数二分

#### 算法思想

在区间内，左半边不满足，右半边满足，寻找边界点。

#### 算法流程

1. 寻找左边的右端点
   1. mid = l + r + 1 >> 1
   2. check(mid) 
      1. true: l = mid
      2. false: r = mid - 1
2. 寻找右边的左端点
   1. mid = l + r >> 1
   2. check(mid)
      1. true: r = mid
      2. false: l = mid + 1

#### 模板

```c++
int bsearch_1(int l, int r) {
    while (l < r) {
        int m = l + r + 1 >> 1;
        if (check(m)) l = m;
        else r = m - 1;
    }
    return l;
}

int bsearch_2(int l, int r) {
    while (l < r) {
        int m = l + r >> 1;
        if (check(m)) r = m;
        else l = m + 1;
    }
    return l;
}
```



## 浮点数二分

#### 算法流程

1. mid = (l + r) / 2;
2. check(mid)
   1. true: l = mid
   2. false: r = mid

#### 算法模板

```c++
double bsearch_1(double l, double r) {
    while (r - l > 1e-8) {
        double m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    return l;
}

double bsearch_2(double l, int double r) {
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    return l;
}
```



## 高精度加法

#### 算法思想

模拟竖式

#### 算法模板

```c++
vector<int> add(vector<int> & a, vector<int> & b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(1);
    
    return c;
}
```





## 高精度减法

#### 算法步骤

1. 比较两个数A，B的大小，让大的减去小的
2. 做减法
3. 去除前导0

#### 算法模板

```c++
bool cmp (const vector<int> & A, const vector<int> & B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i]) return A[i] > B[i];
    return true;
}

vector<int> sub(const vector<int> & A, const vector<int> & B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        t += A[i];
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = -1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```





## 大整数乘以小整数

#### 算法步骤

1. t += A[i] * b
2. 把 t % 10，即最低位的结果放进答案
3. t /= 10，t 舍弃最低位
4. 最后需要去除前导0

#### 模板

```c++
vector<int> mul(const vector<int> & A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```





## 大整数除以小整数

#### 算法步骤

1. 每次从最大位开始，取一个，整除 b
2. 结果放进答案，余数再对 b 取余
3. 最后把结果反过来，因为我们的存储格式应该是低位在前
4. 去前导0



#### 算法模板

```c++
vector<int> div(const vector<int> & A, int b, int & r) {
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
```



## 前缀和

#### 一维算法模板

```c++
#include <iostream>
#define fir(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 1e5 + 10;

int sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    fir(i, 1, n) cin >> sum[i], sum[i] += sum[i - 1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }
}
```



#### 二维算法模板

```c++
#include <iostream>
#define fir(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 1000 + 5;
int sum[N][N];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    fir(i, 1, n) fir(j, 1, m)  {    
        scanf("%d", &sum[i][j]);
        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 -1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
    }
}
```



## 差分

#### 思想

${a_1, a_2, \dots, a_n}$

${b_1, b_2, \dots, b_n}$

构造 b数组，使得 $a_i$ 是 $b_1 + b_2 + \dots + b_i$ 即前缀和

即 $前缀和=差分^{-1}$，互为逆运算



#### 算法作用

区间修改变单点修改



#### 一维算法模板

```c++
#include <iostream>
#define fir(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    fir(i, 1, n) scanf("%d", &a[i]);
    fir(i, 1, n) insert(i, i, a[i]);
    
    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    fir(i, 1, n) a[i] = b[i] + a[i - 1];
    
    fir(i, 1, n) printf("%d ", a[i]);
}
```



#### 二维算法模板

```c++
#include <iostream>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define fri(i, b, a) for (int i = b; i >= a; i--)
using namespace std;

const int N = 1e3 + 10;
int a[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    int x1, y1, x2, y2, c;
    cin >> n >> m >> q;
    fir (i, 1, n) fir (j, 1, m) {
        cin >> c;
        insert(i, j, i, j, c);
    }
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    
    fir (i, 1, n) {
        fir (j, 1, m) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
```



## 双指针

#### 算法思想

本来需要两个指针，枚举全部状态$O(N^2)$，但利用某种单调性，可以使复杂度讲到 $O(N)$



#### 算法步骤

1. 暴力做法 $O(N^2)$
2. 找规律优化成 $O(N)$



#### 算法模板

```c++
#include <iostream>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define fri(i, b, a) for (int i = b; i >= a; i--)
using namespace std;

const int N = 1e5 + 10;
int has[N], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n;
    fir(i, 0, n - 1) cin >> a[i];
    
    int ans = 0;
    for (int i = 0, j = 0; j < n; j++) {
        has[a[j]]++;
        while (has[a[j]] > 1) has[a[i++]]--;
        // 这里不用加 i <= j，因为 当 i>j 时，一定为0
        ans = max(ans, j - i + 1);
    }
    
    cout << ans << endl;
}
```



## 位运算

#### 常用操作

1. 求整数 n 的二进制表示中，第 k 位

   1. 把第 k 位移到最低位

   2. 看最低位是几

      ```c++
      int get_k(int n, int k) {
          return (n >> k) & 1;
      }
      ```

2. lowbit，返回最低位的1

   ```c++
   int lowbit(int n) {
       return n & -n;
   }
   ```



## 离散化

#### 适用范围

数据范围很大，但数据量很小，比较稀疏

#### 算法模板

```c++
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
```



## 区间合并

#### 算法思想

贪心

#### 算法步骤

1. 按左端点排序
2. 贪心维护一个区间，有下列三种情况
   1. 包含，那么当前区间不动
   2. 相交，区间右端点更新
   3. 不相交，ans++，当前区间更新为不相交的那个区间

#### 算法模板

```c++
#include <iostream>
#include <algorithm>
#define fir(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;

PII a[N];

int main() {
    int n;
    cin >> n;
    fir(i, 0, n - 1)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n, less<PII>());
    
    int ans = 1;
    int l = a[0].first, r = a[0].second;
    fir(i, 1, n - 1)
        if (a[i].first > r) ans++, l = a[i].first, r = a[i].second;
        else r = max(r, a[i].second);
    
    cout << ans << endl;
}
```



