
# 深度优先搜索（DFS）

深度优先搜索（Depth-First Search, DFS）是一种用于遍历或搜索树或图的算法。其思想是沿着一条路径不断向前，直到不能继续为止，然后回溯到上一个节点，继续搜索其他路径。

## 基本思想

1. 从起始节点出发，访问该节点。
2. 递归地访问每一个未被访问过的相邻节点。
3. 当所有相邻节点都被访问后，回溯到上一个节点，继续搜索。

## 伪代码

```pseudo
DFS(u):
    标记 u 已访问
    for v in u 的所有相邻节点:
        if v 未被访问:
            DFS(v)
```

## 常见应用

- 图的遍历
- 连通分量判定
- 拓扑排序
- 寻找路径/环
- 迷宫求解

## 代码示例（递归实现，邻接表）

```cpp
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
```

## 代码示例（非递归实现，邻接表）

```cpp
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start) {
    stack<int> stk;
    stk.push(start);
    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v]) stk.push(v);
        }
    }
}
```

## 注意事项

- 递归实现时注意栈溢出风险，可用非递归方式避免。
- 对于有向图和无向图，遍历方式略有不同。
- 需要记录访问状态，避免重复访问。

