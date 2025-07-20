# 排序

以下示例中均默认对数组 $a$ 进行排序，其数组长度为 $n$。

## 使用

- 头文件：`#include <algorithm>`
- 用法：`sort(begin, end);` 或 `sort(begin, end, cmp);`

    默认为升序排序，其他排序策略由 $cmp$ 指定。

示例（对数组排序）：
```cpp
sort(a + 1, a + 1 + n);

bool cmp(int x, int y) {
    return x > y;
}

sort(a + 1, a + 1 + n, cmp);
```

示例（对结构体排序）：
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

## 实现

前四种排序方式因时间或空间复杂度过高而不常用。第5，6种更优。

### 1 计数排序

时间复杂度为 $O(n+m)$ ，空间复杂度 $O(m)$ ，其中 $m$ 为数组 $a$ 中元素范围。

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

### 2 选择排序

每次排序时，将最小的元素放在当前位置。时间复杂度为 $O(n^2)$ 。

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

### 3 冒泡排序

每次检查相邻两个元素，若顺序相反，则交换顺序。时间复杂度为 $O(n^2)$ 。

```cpp
for (int i = 1; i < n; i++) {
    for (int j = 1; j < n - i; j++) {
        if (a[j] > a[j + 1]) {
            int tmp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = tmp;
        }
    }
}
```

### 4 插入排序

每次查找当前元素的正确位置并插入。时间复杂度为 $O(n^2)$ 。

```cpp
for (int i = 2; i <= n; i++) {
    int tmp = a[i];
    for (int j = i - 1; j > 0; j--) {
        if (a[j] > tmp) {
            a[j + 1] = a[j];
            break;
        }
        a[j + 1] = tmp;
    }
}
```

### 5 快速排序

将数组一分为二，小于标志数的数存放在左侧，大于标志数的数存放在右侧，然后递归处理标志数左半部分与右半部分。最坏情况下时间复杂度为 $O(n^2)$ ，在随机化情境中时间复杂度为 $O(n \log n)$ 。

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

### 6 归并排序

核心思想为合并两个有序数组，递归地确保每次操作左半部分与右半部分分别有序，然后合并。时间复杂度 $O(n \log n)$ 。

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