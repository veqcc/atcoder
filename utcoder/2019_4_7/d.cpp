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
const ll MOD = 998244353LL;
const int MAX_N = 2000;

ll dp[1005][1005];
// i人以上のチームだけを組んだ時、j人余る組み合わせ数

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
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> c(n+1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }

    COMinit();

    dp[n+1][0] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (dp[i+1][j] == 0) continue;

            int r = j + c[i];
            for (int k = 0; k * i <= r; k++) { // k個のi人グループを作る
                ll tmp = dp[i+1][j];

                tmp *= com(r, k*i);
                tmp %= MOD;

                tmp *= fac[k*i];
                tmp %= MOD;

                tmp *= pow_mod(fiv[i], k, MOD);
                tmp %= MOD;

                tmp *= fiv[k];
                tmp %= MOD;

                dp[i][r - k * i] += tmp;
                dp[i][r - k * i] %= MOD;
            }
        }
    }

    cout << dp[1][0] << "\n";
    return 0;
}