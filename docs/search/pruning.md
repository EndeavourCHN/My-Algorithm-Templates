
# 剪枝（Pruning）

剪枝是一种在搜索算法（如 DFS、BFS、回溯）中提前排除不可能或不优的分支，从而减少搜索空间、提高效率的技巧。

## 基本思想

- 在搜索过程中，判断当前状态是否有可能得到更优解或满足条件。
- 如果不可能，则提前终止该分支的搜索（即“剪掉”）。
- 剪枝可以显著降低时间复杂度，避免无效递归或枚举。

## 常见应用

- 回溯算法（如排列组合、数独、八皇后等）
- 状态空间搜索（如博弈、路径规划）
- 动态规划中的状态转移优化

## 伪代码

```pseudo
function dfs(state):
    if 不满足条件或无解:
        return
    if 到达目标状态:
        更新答案
        return
    for 每个可能的选择:
        if 可以剪枝:
            continue
        dfs(新状态)
```

## 代码示例（八皇后问题中的剪枝）

```cpp
#include <vector>
using namespace std;

int n, ans = 0;
vector<bool> col, diag1, diag2;

void dfs(int row) {
    if (row == n) { ans++; return; }
    for (int c = 0; c < n; ++c) {
        if (col[c] || diag1[row + c] || diag2[row - c + n]) continue; // 剪枝
        col[c] = diag1[row + c] = diag2[row - c + n] = true;
        dfs(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + n] = false;
    }
}

int main() {
    n = 8;
    col.assign(n, false);
    diag1.assign(2 * n, false);
    diag2.assign(2 * n, false);
    dfs(0);
    // ans 即为解的数量
}
```

## 注意事项

- 剪枝条件需保证正确性，不能剪掉可能的最优解。
- 剪枝越充分，搜索越快，但要注意实现复杂度和边界情况。

