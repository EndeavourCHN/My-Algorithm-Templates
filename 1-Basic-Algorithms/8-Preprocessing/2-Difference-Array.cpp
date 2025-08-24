#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, a[MAXN], b[MAXN];
int m, l, r, c;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 预处理一维差分数组
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    cin >> m;
    while (m--) {
        cin >> l >> r >> c; // [l, r]区间加c
        b[l] += c;
        b[r + 1] -= c;
    }
    // 差分数组还原
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    
    return 0;
}
