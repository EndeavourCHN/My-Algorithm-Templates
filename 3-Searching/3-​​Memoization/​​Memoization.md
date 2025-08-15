
# 记忆化搜索（Memoization）

记忆化搜索是一种结合递归和动态规划思想的算法。通过递归求解子问题，并用数组或哈希表记录已经计算过的结果，避免重复计算，提高效率。

## 基本思想

- 用递归实现问题求解。
- 每次递归前，先判断该状态是否已经计算过，若有则直接返回结果。
- 否则递归计算，并将结果保存下来。

## 常见应用

- 斐波那契数列
- 背包问题
- 区间DP
- 树形DP
- 状态空间较大但重复子问题较多的场景

## 伪代码

```pseudo
function dfs(state):
    if 已经计算过 state:
        return 记忆结果
    计算 state 的答案
    保存答案到记忆结构
    return 答案
```

## 代码示例（斐波那契数列）

```cpp
#include <vector>
using namespace std;

vector<int> memo;

int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int N = 30;
    memo.assign(N + 1, -1);
    int ans = fib(N);
}
```

## 注意事项

- 记忆化搜索适合状态空间不太大、递归层数可控的问题。
- 记忆结构可以用数组或哈希表，视状态定义而定。
- 与递推式DP相比，记忆化搜索更易实现但有时空间和时间效率略低。

