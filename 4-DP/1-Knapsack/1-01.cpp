#include <bits/stdc++.h>
#define maxm 10000010
using namespace std;

int m, n, w, v, dp[maxm];

int main() {
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w >> v;
		for(int j = m; j >= w; j--) { // 逆序遍历，防止一个物品被重复选取
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[m];
	
	return 0;
}
