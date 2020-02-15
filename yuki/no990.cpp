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

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    char op;
    cin >> op;

    vector <ll> a(n), b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    if (op == '+') {
        map <ll, ll> mp;
        for (int i = 0; i < n; i++) mp[a[i] % k]++;
        for (int i = 0; i < m; i++) ans += mp[(k - b[i] % k) % k];
    } else {
        map <ll, ll> mp_a, mp_b;
        for (int i = 0; i < m; i++) mp_b[gcd(k, b[i])]++;
        for (int i = 0; i < n; i++) mp_a[gcd(k, a[i])]++;

        auto div = divisor(k);

        for (ll d1 : div) {
            for (ll d2 : div) {
                if (d1 * d2 % k == 0) {
                    ans += mp_a[d1] * mp_b[d2];
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}