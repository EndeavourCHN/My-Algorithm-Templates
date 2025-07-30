# 树形结构

## 1 并查集 (Disjoint Set Union)

### 核心操作

- **find**：查找根节点（路径压缩优化）
- **join**：合并两个集合

### 示例

```cpp
int find(int x) {
	if (x == root[x]) return x;
	return root[x] = find(root[x]); // 路径压缩，查找的同时进行赋值修改，实现记忆化搜索
}

void join(int c1, int c2) {
	int f1 = find(c1), f2 = find(c2);
	if(f1 != f2) root[f1] = f2; // 将f1的根节点指向f2的根节点
}
```

## 2 树状数组 (Fenwick Tree)

适用场景：单点更新，前缀查询

### 核心数学
- **lowbit 计算**：`x & -x` （获取最低位的 $1$ ）
- **索引关系**：
  ```math
  \text{父节点索引} = \text{当前索引} + \text{lowbit(当前索引)}
  ```

### 示例
```cpp
int lowbit(int x) {
	return x & -x; // 获取最低位的1
}

void add(int no, int val) {
	while(no <= n) {
		// 更新各级最值节点
		maxh[no] = max(maxh[no], val);
		minh[no] = min(minh[no], val);
		no += lowbit(no); // 更新到下一级最值节点
	}
}

int findmax(int l, int r) {
	if(r > l) {
        // 如果maxh[r]覆盖区间的左边界大于l，则取maxh[r]和剩余区间的最大值
		if(r - lowbit(r) > l) return max(maxh[r], findmax(l, r - lowbit(r)));
        // 否则，取当前节点和剩余区间内最大值
		else return max(h[r], findmax(l, r - 1));
	}
	return h[l];
}

// 查询区间最小值同理
```

- 时间复杂度 单点更新：$O(\log n)$，前缀查询：$O(\log n)$
- 空间复杂度 $O(n)$