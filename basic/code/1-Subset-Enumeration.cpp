#include <iostream>
#define MAXN 16
using namespace std;

int n, a[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int U = 1 << n; // U = 2^n, 表示全集
    for (int S = 0; S < U; S++) { // 枚举子集
        for (int i = 0; i < n; i++) { // 限制子集中的元素
            if (__builtin_popcount(S) != 2) continue; // 检查子集元素个数
            if (S & (1 << i)) cout << a[i] << ' ';
        }
        if (__builtin_popcount(S) == 2) cout << endl;
    }

    return 0;
}

