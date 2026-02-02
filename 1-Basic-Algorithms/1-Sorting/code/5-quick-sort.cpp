#include <iostream>
#define MAXN 100010
using namespace std;

int n, a[MAXN];

void quickSort(int a[], int l, int r) {
    int i = l, j = r, flag = a[(l + r) / 2], tmp;
    while (i <= j) {
        while (a[i] < flag) i++; // 查找左边第一个大于等于flag的元素
        while (a[j] > flag) j--; // 查找右边第一个小于等于flag的元素
        if(i <= j) { // 交换
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } 
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    quickSort(a, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}