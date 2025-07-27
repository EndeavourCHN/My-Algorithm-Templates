# 倍增 (Binary Lifting)

### 基本概念

倍增算法是一种通过**指数级扩大**来优化计算的思想，核心特点：

1. **预处理**：预先计算不同步长的结果
2. **二进制分解**：将问题分解为 $2$ 的幂次组合
3. **高效查询**：将线性操作优化为对数时间复杂度

典型应用包括快速幂，ST表等等。

### 示例：ST表（稀疏表）

```cpp
#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

int n, q, h[MAXN], log_2[MAXN], rmax[MAXN][18], rmin[MAXN][18]; // rmax[i][j] 表示 i 到 2^j 的最大值，rmin[i][j] 表示 i 到 2^j 的最小值

void init() {
	for (int i = 1; i <= n; i++) { // 初始化
		rmax[i][0] = rmin[i][0] = h[i];
	}
    // 区间大小逐级倍增，记录区间最值
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) { 
			rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << j - 1)][j - 1]);
			rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << j - 1)][j - 1]);
		}
	}
}

int query_max(int A, int B) { // 查询[A, B]区间最大值
	int x = log_2[B - A + 1];
	return max(rmax[A][x], rmax[B - (1 << x) + 1][x]);
}

int query_min(int A, int B) { // 查询[A, B]区间最小值
	int x = log_2[B - A + 1];
	return min(rmin[A][x], rmin[B - (1 << x) + 1][x]);
}

int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int i = 2; i <= n; i++) log_2[i] = log_2[i >> 1] + 1; // 预存储 log2 的值
	init(); // 构建ST表
	while(q--) {
		int A, B;
		cin >> A >> B;
		cout << query_max(A, B) << ' ' << query_min(A, B) << endl;
	}
	
	return 0;
}
```

​**​复杂度分析​​：**

- 预处理： $O(n \log n)$
- 查询： $O(1)$
- 空间： $O(n \log n)$

### 其他应用场景

- LCA（最近公共祖先）
- 后缀数组构建
- 跳表（Skip List）
- 二进制优化DP（如多重背包问题）