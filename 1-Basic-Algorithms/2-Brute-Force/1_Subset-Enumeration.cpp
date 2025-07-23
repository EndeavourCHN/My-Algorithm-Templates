#include <iostream>
#define MAXN 16
using namespace std;

int n, a[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int U = 1 << n;
    for (int S = 0; S < U; S++) {
        for (int i = 0; i < n; i++) {
            if (__builtin_popcount(S) != 2) continue;
            if (S & (1 << i)) cout << a[i] << ' ';
        }
        if (__builtin_popcount(S) == 2) cout << endl;
    }

    return 0;
}

