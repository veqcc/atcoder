#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

// extended Euclid
// ap+bq=gcd(a,b) -> (p, q) & returns d=gcd(a, b)
ll extGCD(ll a, ll b, ll &p, ll &q) {
    if (b == 0) { p = 1; q = 0; return a; }
    ll d = extGCD(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// Chinese Remainder Theorem
// when x = b1 (mod m1)
//      x = b2 (mod m2)
//      m1 * p + m2 * q = d = gcd(m1, m2)
// then x = b1 + m1 * (b1 - b2) / d * p
// if x=r(mod m), returns (r, m)
pair<ll, ll> CRT(const vector<ll> &b, const vector<ll> &m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); i++) {
        ll p, q;
        ll d = extGCD(M, m[i], p, q);
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i]/d;
    }
    return make_pair((r % M + M) % M, M);
}

ll check(ll n, ll m) {
    ll ans = 0;
    while (n) {
        ans += n % m;
        n /= m;
    }
    return ans;
}

int main() {
    ll t;
    vector <ll> a, m;
    for (int i = 1; i <= 29; i++) {
        cin >> t;
        a.push_back(t);
        m.push_back((ll)i);
    }

    ll ans = CRT(a, m).first;

    if (ans <= 0 || ans > 1e12) {
        cout << "invalid" << endl;
        return 0;
    }

    for (int i = 2; i <= 30; i++) {
        ll tmp = ans;
        if (check(tmp, (ll)i) != a.at(i-2)) {
            cout << "invalid" << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}