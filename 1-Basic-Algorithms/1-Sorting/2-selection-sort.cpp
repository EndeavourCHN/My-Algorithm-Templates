#include <iostream>
#define MAXN 1000010
using namespace std;

int n, a[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}