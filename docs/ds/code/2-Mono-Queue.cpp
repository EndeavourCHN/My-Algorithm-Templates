#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int n, k, a[MAXN], q1[MAXN], q2[MAXN], head, tail;

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	head = 0, tail = 0;
	for(int i = 1; i <= n; i++) {
		while(head < tail && q1[head] + k <= i) head++;
		while(head < tail && a[q1[tail - 1]] > a[i]) tail--;
		q1[tail] = i;
		tail++;
		if(i >= k) cout << a[q1[head]] << ' ';
	}
	cout << endl;
	
	head = 0, tail = 0;
	for(int i = 1; i <= n; i++) {
		while(head < tail && q2[head] + k <= i) head++;
		while(head < tail && a[q2[tail-1]] < a[i]) tail--;
		q2[tail] = i;
		tail++;
		if(i >= k) cout << a[q2[head]] << ' ';
	}
	
	return 0;
}
