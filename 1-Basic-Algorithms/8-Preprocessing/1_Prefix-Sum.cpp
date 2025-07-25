#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, a[MAXN], sum[MAXN], m, l, r;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 预处理一维前缀和
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    
    while (m--) {
        cin >> l >> r;
        // 查询区间 [l, r] 的和
        cout << sum[r] - sum[l - 1] << endl;
    }
    
    return 0;
}
