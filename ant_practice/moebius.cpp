#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

// 蟻本p265

map <int, int> moebius(int n) {
    map <int, int> res;
    vector <int> primes;

    // nの素因数を列挙
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) primes.push_back(n);

    int m = primes.size();
    for (int i = 0; i < (1 << m); i++) {
        int mu = 1, d = 1;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                mu *= -1;
                d *= primes[j];
            }
        }
        res[d] = mu;
    }
    return res;
}

const int MOD = 10009;

int pow_mod(int num, int pow) {
    int prod = 1;
    num %= MOD;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % MOD;
        num = num * num % MOD;
        pow >>= 1;
    }
    return prod;
}

int main() {
    int n;
    cin >> n;

    int res = 0;
    map <int, int> mu = moebius(n);
    for (auto itr = mu.begin(); itr != mu.end(); ++itr) {
        res += itr->second * pow_mod(26, n / itr->first);
        res = (res % MOD + MOD) % MOD;
    }

    cout << res << "\n";
    return 0;
}