# 排序

以下示例中均对数组 `a` 进行排序，其数组长度为 $n$。

### 1 计数排序

```cpp
int cnt[MAXN] = {0};
for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
}
for (int i = 1; i <= MAXN; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
        cout << i << ' ';
    }
}
```

### 2 选择排序

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

```cpp
void quickSort(int a[], int l, int r) {
    int i = l, j = r, flag = a[(l + r) / 2], tmp;
    do {
        while (a[i] < flag) i++;
        while (a[j] > flag) j--;
        if(i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}
```

### 6 归并排序

```cpp
void mergeSort(int a[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid, r);
    for (int i = l, j = l, k = mid + 1; i <= r; i++){
        if (j == mid + 1) tmp[i] = a[k++];
        else if(k == r + 1) tmp[i] = a[j++];
        else tmp[i] = a[j] < a[k] ? a[j++] : a[k++];
    }
    for (int i = 1; i <= n; i++) a[i] = tmp[i];
}
```