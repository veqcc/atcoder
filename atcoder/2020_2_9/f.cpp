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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    Combination com(2000005);

    ll ans = 0;
    ans += com.C(r2 + c2 + 2, r2 + 1);
    ans += MOD - com.C(r2 + c1 + 1, r2 + 1);
    ans += MOD - com.C(r1 + c2 + 1, r1);
    ans += com.C(r1 + c1, r1);

    cout << ans % MOD << "\n";
    return 0;
}