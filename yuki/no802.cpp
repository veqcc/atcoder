#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int MAX_N = 2000000;
const ll MOD = 1000000007LL;
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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, m, d1, d2;
    cin >> n >> m >> d1 >> d2;

    ll d = d2 - d1;
    ll x = m - 1 - d1 * (n - 1);
    if (x < 0) {
        cout << 0 << '\n';
        return 0;
    }

    COMinit();

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll tmp = com(n-1, i) * com(x - i*(d+1) + n, n) % MOD;
        if (i % 2 == 0) ans += tmp;
        else ans += MOD - tmp;
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}