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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <ll> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector <ll> fac(n + 1), inv(n + 1), inv_sum(n + 1);
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    inv_sum[0] = 0;
    inv_sum[1] = 1;
    for (ll i = 2; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        inv_sum[i] = (inv_sum[i - 1] + inv[i]) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = (ans + (x[i + 1] - x[i]) * inv_sum[i + 1] % MOD) % MOD;
    }

    cout << ans * fac[n - 1] % MOD << "\n";
    return 0;
}