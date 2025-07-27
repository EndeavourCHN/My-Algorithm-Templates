#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

int n, q, h[MAXN], log_2[MAXN], rmax[MAXN][18], rmin[MAXN][18]; // rmax[i][j] 表示 i 到 2^j 的最大值，rmin[i][j] 表示 i 到 2^j 的最小值

void init() {
	for (int i = 1; i <= n; i++) { // 初始化
		rmax[i][0] = rmin[i][0] = h[i];
	}
    // 区间大小逐级倍增，记录区间最值
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) { 
			rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << j - 1)][j - 1]);
			rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << j - 1)][j - 1]);
		}
	}
}

int query_max(int A, int B) { // 查询[A, B]区间最大值
	int x = log_2[B - A + 1];
	return max(rmax[A][x], rmax[B - (1 << x) + 1][x]);
}

int query_min(int A, int B) { // 查询[A, B]区间最小值
	int x = log_2[B - A + 1];
	return min(rmin[A][x], rmin[B - (1 << x) + 1][x]);
}

int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int i = 2; i <= n; i++) log_2[i] = log_2[i >> 1] + 1; // 预存储 log2 的值
	init(); // 构建ST表
	while(q--) {
		int A, B;
		cin >> A >> B;
		cout << query_max(A, B) << ' ' << query_min(A, B) << endl;
	}
	
	return 0;
}
