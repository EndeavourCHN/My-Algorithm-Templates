# 并查集 (Disjoint Set Union)

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
