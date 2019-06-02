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
const int MAX_N = 2000000;

ll inv[MAX_N], fac[MAX_N], fiv[MAX_N];

void COMinit() {
    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i < MAX_N; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
    }
}

ll com(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * fiv[k] % MOD * fiv[n-k] % MOD;
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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    COMinit();

    ll A = a * inv[a + b] % MOD;
    ll B = b * inv[a + b] % MOD;

    ll ret = 0;
    ll An = pow_mod(A, n, MOD);
    ll Bn = pow_mod(B, n, MOD);

    for (ll i = 0; i < n; i++) {
        ll tmp = An * pow_mod(B, i, MOD) % MOD + Bn * pow_mod(A, i, MOD) % MOD;
        tmp = tmp % MOD * com(n + i - 1, i) % MOD * (n + i) % MOD;
        ret = (ret + tmp) % MOD;
    }

    cout << ret * 100 % MOD * inv[a + b] % MOD << "\n";
    return 0;
}