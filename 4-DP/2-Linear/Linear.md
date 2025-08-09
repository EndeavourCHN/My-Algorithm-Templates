# 线性动态规划（Linear DP）

线性动态规划是指状态转移只与前面若干个线性排列的状态有关的动态规划问题。常见于序列、数组等一维结构的最优解问题。

## 基本思想

- 将问题拆分为若干阶段，每个阶段的最优解只依赖于前面某些阶段的状态。
- 通过递推公式逐步计算出每个阶段的最优解。

## 常见模型

- 最长上升子序列（LIS）
- 最大子段和（Maximum Subarray）
- 斐波那契数列
- 背包问题（线性空间优化）

## 代码示例（最大子段和）

```cpp
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int dp = nums[0], ans = nums[0];
    for (int i = 1; i < n; ++i) {
        dp = max(dp + nums[i], nums[i]);
        ans = max(ans, dp);
    }
    return ans;
}
```

## 代码示例（最长上升子序列）

```cpp
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
```

## 代码示例（最长公共子串）

```cpp
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 返回最长公共子串的长度
int longestCommonSubstring(const string& a, const string& b) {
    int n = a.size(), m = b.size(), ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}
```

## 注意事项

- 明确状态定义和转移方程。
- 初始状态要正确设置。
- 可以根据题目优化空间复杂度（如滚动数组）。

