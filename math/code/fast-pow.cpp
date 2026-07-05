#include <iostream>
#define ll long long
using namespace std;

ll b, e, mod;

ll fastPow(ll b, ll e) {
    ll result = 1;
    while (e > 0) {
        if (e & 1) {  // 检查指数是否为奇数
            result *= b;
        }
        b *= b;
        e >>= 1;  // 指数右移一位，相当于除以2
    }
    return result;
}

ll fastPowMod(ll b, ll e, ll mod) {
    ll result = 1;
    while (e > 0) {
        if (e & 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        e >>= 1;
    }
    return result;
}

int main() {
    cin >> b >> e >> mod;
    if (mod == 0) cout << fastPow(b, e) << endl;
    else cout << fastPowMod(b, e, mod) << endl;
    
    return 0;
}
