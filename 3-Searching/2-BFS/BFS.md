
# 广度优先搜索（BFS）

广度优先搜索（Breadth-First Search, BFS）是一种用于遍历或搜索树或图的算法。其思想是从起始节点出发，首先访问所有距离起点最近的节点，然后逐层向外扩展，直到遍历完所有节点或找到目标节点。

## 基本思想

1. 从起始节点出发，将其加入队列并标记为已访问。
2. 不断从队列中取出节点，访问其所有未被访问过的相邻节点，并将这些节点加入队列。
3. 重复上述过程，直到队列为空或找到目标节点。

## 伪代码

```pseudo
BFS(u):
    创建队列 Q
    Q.push(u)
    标记 u 已访问
    while Q 非空:
        x = Q.front(); Q.pop()
        for v in x 的所有相邻节点:
            if v 未被访问:
                Q.push(v)
                标记 v 已访问
```

## 常见应用

- 最短路径问题（无权图）
- 连通分量判定
- 拓扑排序（Kahn算法）
- 迷宫求解
- 状态空间搜索

## 代码示例（邻接表）

```cpp
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

## 注意事项

- BFS 通常用于求最短路径（步数最少），适合无权图。
- 需要使用队列维护当前层的节点。
- 需要记录访问状态，避免重复访问。
- 对于大图，BFS 可能消耗较多内存。

