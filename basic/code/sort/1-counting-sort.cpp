#include <iostream>
#define MAXN 100010
using namespace std;

int n, a[MAXN], cnt[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            cout << i << ' ';
        }
    }

    return 0;
}