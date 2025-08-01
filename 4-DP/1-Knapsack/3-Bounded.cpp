#include <iostream>
#define maxm 10000010
#define maxn 100010
using namespace std;

int m, n, w, v, s, dp[maxm];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> v >> s;
        for (int k = 1; k <= s; k *= 2) { // 分解为2的幂次
            int kv = k * v, kw = k * w;
            // 0/1背包过程
            for (int j = m; j >= kw; j--) {
                dp[j] = max(dp[j], dp[j - kw] + kv);
            }
            s -= k;
        }
        
        // 处理剩余部分
        if (s > 0) {
            int sv = s * v, sw = s * w;
            for (int j = m; j >= sw; j--) {
                dp[j] = max(dp[j], dp[j - sw] + sv);
            }
        }
    }
    cout << dp[m] << endl;

    return 0;
}
