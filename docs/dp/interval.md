
# 区间动态规划（Interval DP）

区间动态规划是一类状态与区间相关的动态规划问题，常用于求解区间分割、合并、最优划分等问题。状态通常表示某个区间的最优解。

## 基本思想

- 状态定义为区间 $[l, r]$ 的最优解（如最小代价、最大得分等）。
- 状态转移通常枚举区间分割点 $k$，将区间分为两部分，递归求解并合并。

## 常见模型

- 石子合并（区间合并最小代价）
- 括号匹配
- 多边形划分
- 回文串分割

## 伪代码（石子合并）

```pseudo
for len = 2 to n:
    for l = 1 to n - len + 1:
        r = l + len - 1
        dp[l][r] = INF
        for k = l to r - 1:
            dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + cost(l, r))
```

## 代码示例（石子合并）

```cpp
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n;
vector<int> a, sum;
vector<vector<int>> dp;

int main() {
    // 输入 n 和 a[1..n]
    // sum[i] = a[1] + ... + a[i]
    dp.assign(n + 1, vector<int>(n + 1, 0));
    sum.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l; k < r; ++k) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + sum[r] - sum[l-1]);
            }
        }
    }
    // dp[1][n] 即为答案
}
```

## 注意事项

- 区间 DP 通常需要三重循环，时间复杂度 $O(n^3)$，可通过四边形不等式等优化到 $O(n^2)$。
- 预处理前缀和等辅助数组可加速区间求和。
- 状态定义和转移方程需结合具体题目分析。

