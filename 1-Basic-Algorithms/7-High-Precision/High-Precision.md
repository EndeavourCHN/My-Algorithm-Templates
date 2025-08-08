# 高精度

### 基本思想

- 用数组或字符串存储大整数的每一位（通常低位在前，高位在后）。
- 按位模拟手算过程，实现加减乘除等基本运算。

### 代码示例

**加法**

```cpp
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
```

**乘法**

```cpp
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
```

### 注意事项

- 输入输出时需将字符串转为数组，输出时逆序打印。
