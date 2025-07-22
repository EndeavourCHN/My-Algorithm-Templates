#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 1000010
using namespace std;

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

int main() {
    euler_sieve();
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    return 0;
}