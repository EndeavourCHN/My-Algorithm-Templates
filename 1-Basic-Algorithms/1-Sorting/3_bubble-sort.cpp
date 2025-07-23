#include <iostream>
#define MAXN 1000010
using namespace std;

int n, a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}