# 快速幂

快速幂（Fast Exponentiation）是一种高效计算大数幂运算的算法，能够将时间复杂度从 $O(n)$ 降低到 $O(\log{n})$ 。

### 基本原理
快速幂基于以下数学原理：

- 当指数为偶数时：$a^n = (a^{n/2})^2$
- 当指数为奇数时：$a^n = a \times a^{n-1}$

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

### 核心思想
1. 二进制分解：将指数按二进制位进行分解
2. 逐步累乘：根据二进制位决定是否累乘到结果中
3. 底数倍增：每次将底数平方，对应指数减半

### 应用场景
大数模幂运算
矩阵快速幂
逆元计算
组合数学问题

### 复杂度
时间复杂度： $O(\log{n})$
空间复杂度： $O(1)$