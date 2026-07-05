# 树上的动态规划

树上背包问题

- 按照后序遍历序列创建新编号，确保子节点编号小于父节点且连续。随后可视为子节点为物品，父节点为背包的背包问题。

```cpp
#include <bits/stdc++.h>
#define maxn 3010
using namespace std;

int n, m, pro[maxn], cst[maxn], _cnt, _to, _cst;
int dp[maxn][maxn], num[maxn], tosz[maxn], nm;
vector<int> to[maxn];

void dfs(int x){
	tosz[x] = 1;
	for(int i = 0; i < to[x].size(); i++){
		dfs(to[x][i]);
		tosz[x] += tosz[to[x][i]];
	}
	num[++nm] = x;
	//cout << nm << ' ' << x << endl;
	//cout << x << ' ' << tosz[x] << endl;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n - m; i++){
		cin >> _cnt;
		for(int j = 1; j <= _cnt; j++){
			cin >> _to >> _cst;
			to[i].push_back(_to);
			cst[_to] = _cst;
		}
	}
	for(int i = n - m + 1; i <= n; i++) cin >> pro[i];
	memset(dp, 0xcf, sizeof(dp));
	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	dfs(1);
	for(int i = 1; i <= n; i++){
		int tmp = num[i];
		for(int j = m; j >= 1; j--){
			if(tmp > n - m) dp[i][j] = max(dp[i - 1][j - 1] + pro[tmp] - cst[tmp], dp[i - 1][j]);
			else{
				dp[i][j] = max(dp[i - 1][j] - cst[tmp], dp[i - tosz[tmp]][j]);
			}
			//cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	}
	for(int i = m; i >= 0; i--){
		if(dp[n][i] >= 0){
			cout << i;
			return 0;
		}
	}
	
	return 0;
}

```
