#include <iostream>
#define MAXN 1000010
using namespace std;

int n, a[MAXN], x;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int l = 1, r = n + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (l <= n && a[l] == x) { // 确认找到，输出索引，即 l 指向的位置
        cout << l << endl;
    }
    else cout << -1 << endl; // 未找到，输出 -1

    return 0;
}