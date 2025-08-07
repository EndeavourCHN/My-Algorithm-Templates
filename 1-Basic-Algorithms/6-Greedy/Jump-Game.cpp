#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

int n, a[maxn], farthest = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i > farthest) {
            cout << "NO" << endl;
            return 0;
        }
        farthest = max(farthest, i + a[i]);
    }
    cout << "YES" << endl;

    return 0;
}
