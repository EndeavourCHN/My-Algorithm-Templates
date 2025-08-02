#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 1000010
using namespace std;

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

int main() {
    eratosthenes();
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    return 0;
}
