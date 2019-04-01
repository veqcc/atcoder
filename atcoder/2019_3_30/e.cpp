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
const int MAX_N = 2000005;

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

    int B, W;
    cin >> B >> W;

    COMinit();

    ll b = 1, w = 1, base = 1;
    for (int i = 1; i <= B+W; i++) {
        ll ans = (b - w * fiv[2]) % MOD;
        ans = (ans + MOD) % MOD;
        ans = (ans * base) % MOD;
        cout << ans << "\n";

        base = (base * fiv[2]) % MOD;
        b = (b * 2) % MOD;
        w = (w * 2) % MOD;

        if (i >= B) {
            b = (b + MOD - com(i-1, B-1)) % MOD;
            w = (w + MOD - com(i-1, B-1)) % MOD;
        }

        if (i >= W) {
            w = (w + MOD - com(i-1, i-W)) % MOD;
        }
    }

    return 0;
}