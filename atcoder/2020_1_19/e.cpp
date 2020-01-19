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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector <ll> fac(1000001), inv(1000001), fiv(1000001);
    fac[0] = inv[0] = fiv[0] = fac[1] = inv[1] = fiv[1] = 1;
    for (ll i = 2; i <= 1000000; i++) {
        fac[i] = fac[i - 1] * i % MOD; // n!
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
        fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
    }

    map<int, int> mp;
    for (int i = 1; i < n; i++) {
        ll g = gcd(A[0], A[i]);
        ll tmp = A[i] / g; // 最終的にtmp倍する必要がある。

        auto primes = prime_factor(tmp);
        for (auto itr = primes.begin(); itr != primes.end(); itr++) {
            mp[itr->first] = max(mp[itr->first], itr->second);
        }
    }

    ll l = 1;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        for (int i = 0; i < itr->second; i++) {
            l = l * itr->first % MOD;
        }
    }

    ll ans = l;
    for (int i = 1; i < n; i++) {
        ll tmp = A[0] * l % MOD * inv[A[i]] % MOD;
        ans = (ans + tmp) % MOD;
    }

    cout << ans << "\n";
    return 0;
}