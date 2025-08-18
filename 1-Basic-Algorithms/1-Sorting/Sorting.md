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

- 基本思想：通过计数，将元素分类，然后根据分类结果进行排序
- 时间复杂度： $O(n+m)$ 
- 空间复杂度： $O(m)$ 

  其中 $m$ 为数组 $a$ 中元素范围。

```cpp
int cnt[m] = {0};
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

- 基本思想：找到当前位置的元素，将其与最小的元素交换位置。
- 时间复杂度： $O(n^2)$
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

- 基本思想：通过比较相邻两个元素，将较大的元素交换到后面。
- 时间复杂度： $O(n^2)$
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

- 基本思想：查找当前元素的正确位置，并插入。
- 时间复杂度： $O(n^2)$
- 空间复杂度： $O(1)$

```cpp
for (int i = 2; i <= n; i++) {
    int tmp = a[i];
    int j;
    for (j = i - 1; j > 0; j--) {
        if (a[j] > tmp) a[j + 1] = a[j];
        else break;
    }
    a[j + 1] = tmp;
}
```

### 5 快速排序 (Quick Sort)

- 基本思想：通过一趟排序将待排序记录分割成独立的两部分，其中一部分记录的关键字均比另一部分关键字小，则分别对这两部分继续进行排序，直到整个序列有序。
- 时间复杂度：最坏情况下为 $O(n^2)$ ，在随机化情境中为 $O(n \log n)$
- 空间复杂度： $O(1)$

```cpp
void quickSort(int a[], int l, int r) {
    int i = l, j = r, flag = a[(l + r) / 2], tmp;
    while (i <= j) {
        while (a[i] < flag) i++;
        while (a[j] > flag) j--;
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

- 基本思想：合并两个有序数组，递归地确保每次操作左半部分与右半部分分别有序，然后合并。
- 时间复杂度： $O(n \log n)$
- 空间复杂度： $O(n)$

```cpp
void mergeSort(int a[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    for (int i = l, j = l, k = mid + 1; i <= r; i++){
        if (j == mid + 1) tmp[i] = a[k++];
        else if(k == r + 1) tmp[i] = a[j++];
        else tmp[i] = a[j] < a[k] ? a[j++] : a[k++];
    }
    for (int i = l; i <= r; i++) a[i] = tmp[i];
}
```
