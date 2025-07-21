# 质数筛

### 埃氏筛

```cpp
vector<bool> is_prime(n + 1, true);
vector<int> primes;

void eratosthenes() {
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}
```

### 欧拉筛

```cpp
vector<bool> is_prime(n + 1, true);
vector<int> primes;

void euler_sieve() {
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break; // 关键：保证每个合数只被最小质因数筛掉
        }
    }
}
```
