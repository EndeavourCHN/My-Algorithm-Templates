# 贪心（Greedy）

贪心算法是一种在每一步选择中都采取当前状态下的局部最优解，从而希望通过一系列局部最优选择达到全局最优或近似最优的算法。

### 基本思想

- 每一步都做出在当前看来最优的选择（即“贪心”）。
- 不回溯、不考虑整体，只关注当前决策。
- 适用于某些具有“贪心性质”的问题。

### 常见应用

- 区间调度问题
- Huffman 编码
- 最小生成树（Prim/Kruskal）
- Dijkstra 最短路
- 零钱兑换问题
- 活动选择问题
- 跳跃游戏

### 示例（跳跃游戏）

跳跃游戏（LeetCode 55）：判断是否能从数组起点跳到终点。

```cpp
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}
```

### 注意事项

- 贪心算法不一定总能得到最优解，需证明问题具有贪心性质。
- 有些问题需结合动态规划或其他方法解决。

