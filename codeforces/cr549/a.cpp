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

int main() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    ll m = n * k;

    vector <ll> s, t(2 * n);
    for (ll i = 0; i < n; i++) { // n個のレストラン
        ll restaurant = i * k;

        ll front = restaurant + a;
        if (front >= 0 && front < k) s.push_back(front);

        ll back = restaurant - a;
        if (back >= 0 && back < k) s.push_back(back);

        t[i * 2] = restaurant + b;
        t[i * 2 + 1] = restaurant - b;
    }

    ll mn = m, mx = 0;
    for (ll i : s) {
        for (ll j : t) {
            ll num = m / gcd(m, (j - i + 2 * m) % m);
            mn = min(mn, num);
            mx = max(mx, num);
        }
    }

    cout << mn << " " << mx << "\n";
    return 0;
}