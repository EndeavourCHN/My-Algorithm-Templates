# 离散化

离散化是一种将原本取值范围很大或不连续的数据，映射到一个较小的连续整数区间的技巧，常用于数据范围过大但数据种类较少的场景。

### 基本思想

- 将所有需要处理的数收集起来，去重、排序。
- 用每个数在排序后数组中的下标来代替原数值。

### 示例（区间覆盖）

```cpp
#include <bits/stdc++.h>
#define MAXN 20010
#define ll long long
using namespace std;

ll n, a[MAXN], b[MAXN], f[MAXN*2], dtop, ctop, d[MAXN*2], c[MAXN*2], ans;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
        // 存入散点
		d[++dtop] = a[i];
		d[++dtop] = b[i];
	}
	sort(d + 1, d + 1 + dtop); // 排序
	for(int i = 1; i <= dtop; i++) {
		if(d[i] != d[i - 1] || i == 1) c[++ctop] = d[i]; // 去重
	}
	for(int i = 1; i <= n; i++) {
        // 坐标映射
		int x = lower_bound(c + 1, c + 1 + ctop, a[i]) - c;
		int y = lower_bound(c + 1, c + 1 + ctop, b[i]) - c;
		for(int j = x; j < y; j++) f[j] = 1; // 覆盖区间映射
	}
	for(int i = 1; i < ctop; i++) {
		if(f[i]) ans += c[i + 1] - c[i];
	}
	cout << ans;
	
	return 0;
}
```
