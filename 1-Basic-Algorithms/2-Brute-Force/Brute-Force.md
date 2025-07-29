# 枚举

### 1 子集枚举

使用二进制与位移运算解决。

以枚举数组 $a$ 的子集为例，其元素总数为 $n$ ，时间复杂度 $O(2^n)$ 。

**注意**：数组 $a$ 的元素从下标 $0$ 开始。

```cpp
int U = 1 << n;
for (int S = 0; S < U; S++) {
    for (int i = 0; i < n; i++) {
        if (S & (1 << i)) cout << a[i] << ' ';
    }
    cout << endl;
}
```

如果要限制子集元素个数，可搭配 `__builtin_popcount()` 函数进行判断。该函数作用是判断一个数二进制形式下有多少位值为 $1$ 。

限制子集中元素个数为 $2$ ：

```cpp
int U = 1 << n;
for (int S = 0; S < U; S++) {
    for (int i = 0; i < n; i++) {
        if (__builtin_popcount(S) != 2) continue;
        if (S & (1 << i)) cout << a[i] << ' ';
    }
    if (__builtin_popcount(S) == 2) cout << endl;
}
```

### 2 排列枚举

`next_permutation` 是 C++ STL 中用于生成序列的下一个字典序排列的函数，常用于全排列枚举。

- 头文件：`#include <algorithm>`
- 用法：`next_permutation(begin, end);`
- 返回值：如果存在下一个排列，返回 `true`，否则返回 `false` 并将序列变为最小排列。
- 时间复杂度： $O(n!)$
- **注意**：全排列时要事先将所有元素升序排序，并将其作为第一种排列。

#### 示例：
```cpp
int a[3] = {1, 2, 3};
do {
    for (int i = 0; i < 3; i++) cout << a[i] << " ";
    cout << endl;
} while (next_permutation(a, a + 3));
```

#### 示例输出：
```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```
