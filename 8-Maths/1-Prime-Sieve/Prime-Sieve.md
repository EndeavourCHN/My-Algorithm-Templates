# 质数筛

传统的质数判断方法采用双层遍历，对被判断数及其因数分别遍历。

```cpp
bool is_prime[MAXN + 1];
vector<int> primes;

void sieve(){
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i <= MAXN; i++) {
        for (int j = 2; j <= sqrt(i); j++){
            if (i % j == 0) {
                is_prime[i] = false;
                break;
            }
        }
        if(is_prime[i]) primes.push_back(i);
    }
}
```

其时间复杂度达 $O(n \sqrt{n})$ ，为提高效率，引入两种线性质数筛。

### 1 埃氏筛

埃氏筛从每个质因数出发，标记其倍数为合数。

```cpp
bool is_prime[MAXN + 1];
vector<int> primes;

void eratosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}
```

### 2 欧拉筛

欧拉筛标记合数时确保每个合数只被最小质因数标记，因此较埃氏筛相比效率更高。

```cpp
bool is_prime[MAXN + 1];
vector<int> primes;

void euler_sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for (int i = 2; i <= MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size(); j++) {
            if (i * primes[j] > MAXN) break;
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break; // 关键：保证每个合数只被最小质因数筛掉
        }
    }
}
```
