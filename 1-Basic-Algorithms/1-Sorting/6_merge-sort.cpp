#include <iostream>
#define MAXN 1000010
using namespace std;

int n, a[MAXN], tmp[MAXN];

void mergeSort(int a[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r); // 递归，对左右两个子数组分别进行归并排序
    for (int i = l, j = l, k = mid + 1; i <= r; i++){
        if (j == mid + 1) tmp[i] = a[k++]; // 如果右侧元素已经全部取完，则取左侧元素
        else if(k == r + 1) tmp[i] = a[j++]; // 如果左侧元素已经全部取完，则取右侧元素
        else tmp[i] = a[j] < a[k] ? a[j++] : a[k++]; // 如果左侧元素小于右侧元素，则取左侧元素，否则取右侧元素
    }
    for (int i = l; i <= r; i++) a[i] = tmp[i]; // 将临时数组中的元素复制回原数组
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}