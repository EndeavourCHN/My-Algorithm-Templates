# 排序

排序是将表中元素重新排列，使其满足按照关键字有序的过程。

## 标准库使用

### 基本操作

- 头文件：`#include <algorithm>`
- 用法：`sort(begin, end);` 或 `sort(begin, end, cmp);` ，其中 $begin$ 和 $end$ 分别为数组首元素地址和末元素**后一位**的地址。
- 默认为升序排序，其他排序策略可由 $cmp$ 变量指定。

### 复杂度分析

- 时间复杂度： $O(n \log n)$
- 空间复杂度： $O(1)$ （原地排序）

### 示例

以下示例中均默认对数组 $a$ 进行排序，其数组长度为 $n$。

**对数组排序：**
```cpp
sort(a + 1, a + 1 + n);

bool cmp(int x, int y) {
    return x > y;
}

sort(a + 1, a + 1 + n, cmp);
```

**对结构体排序：**
```cpp
struct Node {
    int no, val;
} node[MAXN];

bool cmp(Node x, Node y) {
    if (x.val == y.val) return x.no < y.no;
    return x.val < y.val;
}

sort(node + 1, node + 1 + n, cmp);
```

## 具体实现

### 1 计数排序 (Counting Sort)

- 基本思想：统计数组中每个值的出现次数，根据统计结果按顺序回填。
- 时间复杂度： $O(n + m)$ 
- 空间复杂度： $O(m)$ 

  其中 $m$ 为数组 $a$ 中元素范围。

```cpp
int cnt[MAXN] = {0};
for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
}
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
        cout << i << ' ';
    }
}
```

### 2 选择排序 (Selection Sort)

- 基本思想：每次从未排序部分选择​​最小（或最大）元素​​，放到已排序部分的末尾。
- 时间复杂度： $O(n ^ 2)$
- 空间复杂度： $O(1)$

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
        if (a[j] < a[i]) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
}
```

### 3 冒泡排序 (Bubble Sort)

- 基本思想：通过​​相邻元素两两比较​​，将较大的元素逐步“冒泡"到数组末端。
- 时间复杂度： $O(n ^ 2)$
- 空间复杂度： $O(1)$

```cpp
for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
        if (a[j] > a[j + 1]) {
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
    }
}
```

### 4 插入排序 (Insertion Sort)

- 基本思想：向前比较并移动比当前元素大的元素，将每个新元素​​插入到已排序部分的正确位置。
- 时间复杂度： $O(n ^ 2)$
- 空间复杂度： $O(1)$

```cpp
for (int i = 2; i <= n; i++) {
    int tmp = a[i], j;
    for (j = i - 1; j > 0; j--) {
        if (a[j] > tmp) a[j + 1] = a[j];
        else break;
    }
    a[j + 1] = tmp;
}
```

### 5 快速排序 (Quick Sort)

- 基本思想：将待排序记录分割成独立的两部分，其中一部分记录的关键字均比另一部分关键字小，然后分别对这两部分继续进行排序。递归地进行上述操作，直到整个序列有序。
- 时间复杂度：最坏情况下为 $O(n^2)$ ，在随机化情境中为 $O(n \log n)$
- 空间复杂度： $O(1)$

```cpp
void quickSort(int a[], int l, int r) {
    int i = l, j = r, flag = a[(l + r) / 2], tmp;
    while (i <= j) {
        while (a[i] < flag) i++; // 查找左边第一个大于等于flag的元素
        while (a[j] > flag) j--; // 查找右边第一个小于等于flag的元素
        // 交换
        if(i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } 
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}
```

### 6 归并排序 (Merge Sort)

- 基本思想：将排序转化为合并两个有序数组，通过递归，确保每次操作左半部分与右半部分分别有序，然后合并。
- 时间复杂度： $O(n \log n)$
- 空间复杂度： $O(n)$ （需要临时数组保存排序过程中产生的有序子数组）

```cpp
void mergeSort(int a[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r); // 递归，对左右两个子数组分别进行归并排序
    for (int i = l, j = l, k = mid + 1; i <= r; i++) {
        if (j == mid + 1) tmp[i] = a[k++]; // 如果右侧元素已经全部取完，则取左侧元素
        else if(k == r + 1) tmp[i] = a[j++]; // 如果左侧元素已经全部取完，则取右侧元素
        else tmp[i] = a[j] < a[k] ? a[j++] : a[k++]; // 如果左侧元素小于右侧元素，则取左侧元素，否则取右侧元素
    }
    for (int i = l; i <= r; i++) a[i] = tmp[i]; // 将临时数组中的元素复制回原数组
}
```
