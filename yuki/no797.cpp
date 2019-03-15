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

const ll MOD = 1000000007;
ll inv[100005], fac[100005], fiv[100005];

ll comb(ll x, ll y) {
    return fac[x] * fiv[y] % MOD * fiv[x-y] % MOD;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    inv[1] = fac[1] = fiv[1] = inv[0] = fac[0] = fiv[0] = 1;
    for (ll i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
    }

    ll a, ans = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = (ans + a * comb(n-1, i) % MOD) % MOD;
    }

    cout << ans << "\n";
    return 0;
}