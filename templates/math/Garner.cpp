#include <algorithm>
#include <vector>
#include <iostream>
typedef long long ll;
using namespace std;

const ll MOD = 1000000007LL;
typedef pair <ll, ll> P;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 拡張Euclidの互除法
// ap + bq = gcd(a, b) となるp,qを求め、return d = gcd(a,b)
ll extGcd(ll a, ll b, ll &p, ll &q) {
    if (b == 0) {
        p = 1; q = 0; return a;
    } else {
        ll d = extGcd(b, a % b, q, p);
        q -= (a / b) * p;
        return d;
    }
}

// 逆元計算 (aとmは互いに素)
ll modinv(ll a, ll m) {
    ll x, y;
    extGcd(a, m, x, y);
    return mod(x, m);
}

// Garner O(N^2) mは全て互いに素である必要がある
//  多倍長整数必要なしにx mod MODを求めるアルゴリズム
//  for each step, solve "coeffs[k] * t[k] + constants[k] = b[k] (mod m[k])"
//   coeffs[k] = m[0]m[1]...m[k-1]
//   constants[k] = t[0] + t[1]m[0] + ... + t[k-1]m[0]m[1]...m[k-2]
ll Garner(vector <ll> b, vector <ll> m, ll MOD) {
    m.push_back(MOD); // 番兵
    vector <ll> coeffs(m.size(), 1);
    vector <ll> constants(m.size(), 0);
    for (int k = 0; k < b.size(); k++) {
        ll t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
        for (int i = k + 1; i < m.size(); i++) {
            (constants[i] += t * coeffs[i]) %= m[i];
            (coeffs[i] *= m[k]) %= m[i];
        }
    }
    return constants.back();
}

// Garner の前処理。法を全て互いに素にする。
ll preGarner(vector <ll> &b, vector <ll> &m, ll MOD) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < i; j++) {
            ll g = gcd(m[i], m[j]);
            if ((b[i] - b[j]) % g != 0) return -1;

            // 素因数を分配していく: https://qiita.com/drken/items/ae02240cd1f8edfc86fd
            m[i] /= g, m[j] /= g;
            ll gi = gcd(m[i], g), gj = g / gi;
            do {
                g = gcd(gi, gj);
                gi *= g, gj /= g;
            } while (g != 1);
            m[i] *= gi, m[j] *= gj;
            b[i] %= m[i], b[j] %= m[j];
        }
    }

    ll res = 1;
    for (int i = 0; i < b.size(); i++) (res *= m[i]) %= MOD;
    return res;
}


// verified
//  https://yukicoder.me/problems/448
void yuki187() {
    int n; cin >> n;
    vector <ll> b(n), m(n);
    bool all_zero = true;
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> m[i];
        if (b[i]) all_zero = false;
    }
    ll lcm = preGarner(b, m, MOD);
    if (all_zero) cout << lcm << '\n';
    else if (lcm == -1) cout << -1 << '\n';
    else cout << Garner(b, m, MOD) << '\n';
}


int main() {
    yuki187();
    return 0;
}