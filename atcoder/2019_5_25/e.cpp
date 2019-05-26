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

const int MAX_N = 200000;

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
    return fac[n] * fiv[k] % MOD * fiv[n - k] % MOD;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;

    ll tate = 0;
    for (ll i = 1; i < m; i++) (tate += i * (m - i)) %= MOD;
    tate = n * n % MOD * tate % MOD;

    ll yoko = 0;
    for (ll i = 1; i < n; i++) (yoko += i * (n - i)) %= MOD;
    yoko = m * m % MOD * yoko % MOD;

    COMinit();
    cout << (yoko + tate) * com(n * m - 2, K - 2) % MOD << "\n";
    return 0;
}