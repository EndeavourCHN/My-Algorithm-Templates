# 快速幂

快速幂是一种高效计算大数幂运算的算法，能够将时间复杂度从 $O(n)$ 降低到 $O(\log{n})$ 。

### 基本思想

1. 逐步累乘：根据指数奇偶性决定是否累乘到结果中
2. 底数倍增：每次将底数平方，对应指数减半

### 具体实现

- 当指数为偶数时： $a^n = (a^\frac{n}{2})^2$
- 当指数为奇数时： $a^n = a \times a^{n-1}$

```cpp
long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {  // 检查指数是否为奇数
            result *= base;
        }
        base *= base;
        exp >>= 1;  // 指数右移一位，相当于除以2
    }
    return result;
}
```

### 复杂度

- 时间复杂度： $O(\log{n})$
- 空间复杂度： $O(1)$
