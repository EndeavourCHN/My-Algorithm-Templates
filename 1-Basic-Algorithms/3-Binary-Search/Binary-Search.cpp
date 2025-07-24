#include <iostream>
#define MAXN 1000010
using namespace std;

int n, a[MAXN], x;

int find(int a[], int x){
    int l = 1, r = n + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int pos = find(a, x);
    if (pos <= n && a[pos] == x) {
        cout << pos << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}