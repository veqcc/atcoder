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
    ll n, m, K;
    cin >> n >> m >> K;

    ll tate = 0;
    for (ll i = 1; i < m; i++) (tate += i * (m - i)) %= MOD;
    tate = n * n % MOD * tate % MOD;

    ll yoko = 0;
    for (ll i = 1; i < n; i++) (yoko += i * (n - i)) %= MOD;
    yoko = m * m % MOD * yoko % MOD;

    Combination Com(200005);
    cout << (yoko + tate) * Com.C(n * m - 2, K - 2) % MOD << "\n";
    return 0;
}