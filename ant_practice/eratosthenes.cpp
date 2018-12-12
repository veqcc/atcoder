#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int prime[100000]; // i番目の素数
bool is_prime[100001]; // trueならiは素数

int sieve(int n) { // sieve : ふるい
    int p = 0;
    fill(is_prime, is_prime + n, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return p;
}

int main() {
    cout << sieve(100) << endl; // 100以下に素数は25個
    return 0;
}