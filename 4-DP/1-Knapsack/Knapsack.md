# 背包动态规划（Knapsack DP）

### 问题原型

给定容量为 $m$ 的背包和 $n$ 件物品（第 $i$ 件物品重量为 $w_i$，价值为 $v_i$），求不超过背包容量的最大价值。

**说明**：状态转移方程中 $dp[i][j]$ 表示在容量为 $j$ 的背包中，从前 $i$ 件物品选择装入可达到的最大价值。

### 1. 0/1 背包

**特点**：每件物品**只能选或不选**

**状态转移方程**：

```math
dp[i][j] = \max(dp[i-1][j], dp[i-1][j-w_i] + v_i)
```

```cpp
for (int i = 1; i <= n; i++) {
    cin >> w >> v;
    for (int j = m; j >= w; j--) { // 逆序遍历，防止一个物品被重复选取
        dp[j] = max(dp[j], dp[j - w] + v);
    }
}
```

### 2. 完全背包

**特点**：每件物品**可以选无限次**

**状态转移方程**：

```math
dp[i][j] = \max(dp[i-1][j], dp[i][j-w_i] + v_i)
```

```cpp
for (int i = 1; i <= n; i++) {
    cin >> w >> v;
    for (int j = w; j <= m; j++) { // 正序遍历
        dp[j] = max(dp[j], dp[j - w] + v);
    }
}
```

### 3. 多重背包

**特点**：第 $i$ 件物品最多选 $s_i$ 次

```cpp
for (int i = 1; i <= n; ++i) {
    cin >> w >> v >> s;
    for (int k = 1; k <= s; k *= 2) { // 分解为2的幂次
        int kv = k * v, kw = k * w;
        // 0/1背包过程
        for (int j = m; j >= kw; j--) {
            dp[j] = max(dp[j], dp[j - kw] + kv);
        }
        s -= k;
    }
    
    // 处理剩余部分
    if (s > 0) {
        int sv = s * v, sw = s * w;
        for (int j = m; j >= sw; j--) {
            dp[j] = max(dp[j], dp[j - sw] + sv);
        }
    }
}
```
