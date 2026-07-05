#include <iostream>
#include <string>
#define maxn 5010
using namespace std;

int a[maxn], b[maxn], c[maxn];
string A, B;
int main() {
	cin >> A >> B;
	int lena = A.length(), lenb = B.length();
	for(int i = lena - 1; i >= 0; i--) a[lena - i] = A[i] - '0';
	for(int i = lenb - 1; i >= 0; i--) b[lenb - i] = B[i] - '0';
	for(int i = 1; i <= lena; i++) {
		for(int j = 1; j <= lenb; j++) {
			c[i + j - 1] += a[i] * b[j]; // 模拟逐位乘法
		}
	}
	int len = lena + lenb;
    // 处理进位
	for(int i = 1; i <= len; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	for(;!c[len];) {
		len--; // 去除前导0
	}
    // max(1, len) 确保结果为 0 时仍有输出
	for(int i = max(1, len); i >= 1; i--) cout << c[i];

	return 0;
}
