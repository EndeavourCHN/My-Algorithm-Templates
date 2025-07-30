#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;

int n, m, p, x, y;
int root[MAXN];

int find(int x) {
	if (x == root[x]) return x;
	return root[x] = find(root[x]); // 路径压缩，查找的同时进行赋值修改，实现记忆化搜索
}

void join(int c1, int c2) {
	int f1 = find(c1), f2 = find(c2);
	if(f1 != f2) root[f1] = f2; // 将f1的根节点指向f2的根节点
}

int main() {
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++) root[i] = i; // 初始化每个节点的父节点为自身
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		join(x, y); // 合并
	}
	for(int i = 0; i < p; i++) {
		cin >> x >> y;
        // 判断两个节点是否在同一个集合中
		if(find(x) == find(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
