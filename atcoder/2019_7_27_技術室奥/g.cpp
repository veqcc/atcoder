#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while (q--) {
        ll n;
        cin >> n;

        if (n < 5) {
            cout << n << ' ';
            continue;
        }

        if (n % 3 == 0) {
            cout << pow_mod(3, n / 3, MOD) << ' ';
        } else if (n % 3 == 1) {
            cout << pow_mod(3, n / 3 - 1, MOD) * 4 % MOD << ' ';
        } else {
            cout << pow_mod(3, n / 3, MOD) * 2 % MOD << ' ';
        }
    }

    return 0;
}