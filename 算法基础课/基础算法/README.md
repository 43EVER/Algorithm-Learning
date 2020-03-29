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

~~~c++
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
~~~



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

~~~c++
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
~~~



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

