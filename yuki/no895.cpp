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

class Combination {
public:
    vector <ll> fac, inv, fiv;
    Combination(int N) : fac(N + 1), inv(N + 1), fiv(N + 1) {
        fac[0] = inv[0] = fiv[0] = fac[1] = inv[1] = fiv[1] = 1;
        for (ll i = 2; i <= N; i++) {
            fac[i] = fac[i - 1] * i % MOD; // n!
            inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
            fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
        }
    }
    ll C(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[k] % MOD * fiv[n - k] % MOD;
    }
};

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

    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b + c;

    Combination com(sum);

    ll ans = 0;
    for (ll i = c - 1; i < sum - 2; i++) {
        // zの戦闘がibit目であるときを考える
        ll tmp = (com.C(sum - c - 1, b) - com.C(i - c + 1, b) + MOD) % MOD;
        tmp = tmp * com.C(i, c - 1) % MOD;
        ans += pow_mod(2, i, MOD) * tmp % MOD;

        tmp = tmp * (c - 1) % MOD * com.inv[i] % MOD;
        ans += (pow_mod(2, i, MOD) - 1) * tmp % MOD;

        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}