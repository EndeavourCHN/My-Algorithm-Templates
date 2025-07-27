#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void move(char A, char B) {
    cout << A << " --> " << B << endl;
	cnt++;	
}

/**
 * 将 n 个盘子从柱 A 移动到柱 C，需要先将 n-1 个盘子从 A 移动到 B，
 * 然后将最下面的盘子从 A 移动到 C，再将 n-1 个盘子从 B 移动到 C。
 * 于是每次递归调用都会将问题规模减小 1，直到只剩下一个盘子为止。
 */

void Hanoi(int n, char A, char B, char C) {
	if (n == 1) move(A, C); // 只有一个盘子，直接从 A 移动到 C
	else{
		Hanoi(n-1, A, C, B); // 将 n-1 个盘子从 A 移动到 B，C 为辅助柱
		move(A, C);
		Hanoi(n-1, B, A, C); // 将 n-1 个盘子从 B 移动到 C，A 为辅助柱
	}
}

int main() {
	int n;
    cin >> n;
	Hanoi(n, 'A', 'B', 'C'); // A 为起始柱，B 为辅助柱，C 为目标柱
    cout << "Total moves: " << cnt << endl;
    
	return 0;
}
