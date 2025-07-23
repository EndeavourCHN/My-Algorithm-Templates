#include <iostream>
#include <algorithm>
#define MAXN 16
using namespace std;

int n, a[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    do {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    } while (next_permutation(a, a + n));
    
    return 0;
}