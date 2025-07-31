#include <bits/stdc++.h>
#define maxm 10000010
#define maxn 100010
using namespace std;

int m, n, w[maxn], v[maxn], dp[maxm];

int main() {
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		for(int j = w[i]; j <= m; j++) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m];
	
	return 0;
}
