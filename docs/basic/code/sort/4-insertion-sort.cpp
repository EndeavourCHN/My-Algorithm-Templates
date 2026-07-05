#include <iostream>
#define MAXN 100010
using namespace std;

int n, a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int tmp = a[i], j;
        for (j = i - 1; j > 0; j--) {
            if (a[j] > tmp) a[j + 1] = a[j];
            else break;
        }
        a[j + 1] = tmp;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}