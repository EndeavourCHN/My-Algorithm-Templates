#include <bits/stdc++.h>
#define maxn 3000010
using namespace std;

int n, a[maxn], f[maxn];
stack<int> st;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--){
		while(!st.empty() && a[i] >= a[st.top()]) st.pop();
		if(!st.empty()) f[i] = st.top();
		st.push(i);
	}
	for(int i = 1; i <= n; i++) cout << f[i] << ' ';
	
	return 0;
}
