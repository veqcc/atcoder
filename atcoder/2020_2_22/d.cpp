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

    ll P(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[n - k] % MOD;
    }

    ll H(ll n, ll k) {
        if (n == 0 && k == 0) return 1;
        return C(n + k - 1, k - 1);
    }
};

ll binomial(ll N, ll K) {
    if (K < 0 || N < K) return 0;

    Combination com(200005);

    ll ret = 1;
    for (ll i = 1; i <= K; i++) {
        ret *= N--;
        ret %= MOD;
        ret *= com.inv[i];
        ret %= MOD;
    }

    return ret;
}

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

    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = pow_mod(2, n, MOD);
    ans = (ans - 1 + MOD) % MOD;
    ans = (ans - binomial(n, a) + MOD) % MOD;
    ans = (ans - binomial(n, b) + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}