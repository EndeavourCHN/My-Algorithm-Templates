#include <iostream>
#include <string>
#define maxn 1024
using namespace std;

// a, b, c 存储时均为低位在前
int a[maxn], b[maxn], c[maxn];
string A, B;

int main() {
	cin >> A >> B;
	int len = max(A.length(), B.length());
    // 将字符串转存为数组
	for(int i = A.length() - 1, j=1; i >= 0; i--, j++) a[j] = A[i] - '0';
	for(int i = B.length() - 1, j=1; i >= 0; i--, j++) b[j] = B[i] - '0';
	for(int i = 1; i <= len; i++) {
		c[i] += a[i] + b[i];
		c[i + 1] = c[i] / 10; // 进位
		c[i] %= 10;
	}
	if(c[len + 1]) len++;
	for(int i = len; i >= 1; i--) cout << c[i];

	return 0;
}
