# 分治 (Divide and Conquer)

将原问题分解为若干个相互独立且结构相同的子问题，递归求解子问题后合并结果以解决原问题。

### 基本思想

1. **分解** (Divide)：将原问题分解为若干子问题
2. **解决** (Conquer)：递归地解决各个子问题
3. **合并** (Combine)：将子问题的解合并为原问题的解

### 示例（归并排序）

```cpp
void mergeSort(int a[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r); // 分治，将原问题分解为分别排序左子数组和右子数组
    for (int i = l, j = l, k = mid + 1; i <= r; i++){
        if (j == mid + 1) tmp[i] = a[k++];
        else if(k == r + 1) tmp[i] = a[j++];
        else tmp[i] = a[j] < a[k] ? a[j++] : a[k++];
    }
    for (int i = l; i <= r; i++) a[i] = tmp[i];
}
```

### 应用场景

- 快速排序
- 归并排序
- 汉诺塔问题（[示例程序](Hanoi.cpp)）\
  ……