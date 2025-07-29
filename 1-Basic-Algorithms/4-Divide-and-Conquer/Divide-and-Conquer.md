# 分治 (Divide and Conquer)

### 基本思想

分治是一种递归式的问题解决方法，包含三个步骤：

1. **分解** (Divide)：将原问题分解为若干子问题
2. **解决** (Conquer)：递归地解决各个子问题
3. **合并** (Combine)：将子问题的解合并为原问题的解

### 示例：归并排序

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

### 适用场景

1. 问题可以分解为相同类型的子问题
2. 子问题可以独立求解
3. 子问题的解可以合并为原问题的解

### 其他分治算法示例

- 快速排序
- 二分查找
- 大整数乘法
- 最近点对问题
- 汉诺塔问题（示例代码）