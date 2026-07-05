#include <bits/stdc++.h>
#define maxm 100010
using namespace std;

int m, n, w, v, dp[maxm];

int main() {
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w >> v;
		for(int j = w; j <= m; j++) { // 正序遍历，循环中可用到本轮已装入该物品的情况
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[m] << endl;
	
	return 0;
}
