#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

int n, q, a, b;
int h[MAXN], maxh[MAXN], minh[MAXN];

int lowbit(int x) {
	return x & -x; // 获取最低位的1
}

void add(int no, int val) {
	while(no <= n) {
		// 更新各级最值节点
		maxh[no] = max(maxh[no], val);
		minh[no] = min(minh[no], val);
		no += lowbit(no); // 更新到下一级最值节点
	}
}

int findmax(int l, int r) {
	if(r > l) {
        // 如果maxh[r]覆盖区间的左边界大于l，则取maxh[r]和剩余区间的最大值
		if(r - lowbit(r) > l) return max(maxh[r], findmax(l, r - lowbit(r)));
        // 否则，取当前节点和剩余区间内最大值
		else return max(h[r], findmax(l, r - 1));
	}
	return h[l];
}

// 查询区间最小值同理
int findmin(int l, int r) {
	if(r>l) {
		if(r - lowbit(r) > l) return min(minh[r], findmin(l, r - lowbit(r)));
		else return min(h[r], findmin(l, r - 1));
	}
	return h[l];
}

int main() {
	memset(minh, 0x3f3f3f3f, sizeof(minh));
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
		add(i, h[i]);
	}
	for(int i = 1; i <= q; i++) {
		cin >> a >> b;
		cout << findmax(a, b) << ' ' << findmin(a, b) << endl;
	}
	
	return 0;
}
