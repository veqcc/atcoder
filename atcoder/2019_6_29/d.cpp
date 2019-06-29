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

const int MAX_N = 100000;
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
    cout.tie(0);

    ll n, k;
    cin >> n >> k;

    ll red = n - k;

    COMinit();

    for (ll i = 1; i <= k; i++) {
        if (red == 0) {
            ll ans = 0;
            if (i == 1) ans = 1;
            cout << ans << "\n";
            continue;
        }

        ll blue = com(k-1, i-1);

        ll r = 0;
        r = com(red - 1, i - 1) * 2 % MOD;
        r = (r + com(red - 1, i - 2)) % MOD;
        r = (r + com(red - 1, i)) % MOD;

        cout << blue * r % MOD << "\n";
    }

    return 0;
}