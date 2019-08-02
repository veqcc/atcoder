#include <iostream>
#include <vector>
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

    ll P(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[n - k] % MOD;
    }

    ll H(ll n, ll k) {
        if (n == 0 && k == 0) return 1;
        return C(n + k - 1, k - 1);
    }
};


// verified
//   https://yukicoder.me/problems/no/117
void yuki117() {
    int T;
    cin >> T;
    Combination com(2000005);
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = 0, k = 0, i = 2;
        while (s[i] != ',') { n *= 10; n += s[i++] - '0'; }
        i++;
        while (s[i] != ')') { k *= 10; k += s[i++] - '0'; }
        if (s[0] == 'C') cout << com.C(n, k) << "\n";
        else if (s[0] == 'P') cout << com.P(n, k) << "\n";
        else cout << com.H(k, n) << "\n";
    }
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_B
void AOJ_DPL_5_B() {
    int n, k;
    cin >> n >> k;
    Combination com(k);
    cout << com.P(k, n) << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C
ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1; num %= mod;
    while (pow > 0) { if (pow & 1) prod = prod * num % mod; num = num * num % mod; pow >>= 1; }
    return prod;
}
void AOJ_DPL_5_C() {
    int n, k;
    cin >> n >> k;
    Combination com(k);
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ll sgn = i % 2 == 0 ? 1 : -1;
        ans = (ans + MOD + sgn * com.C(k, k - i) * pow_mod(k - i, n, MOD) % MOD) % MOD;
    }
    cout << ans << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D
void AOJ_DPL_5_D() {
    int n, k;
    cin >> n >> k;
    Combination com(n + k);
    cout << com.H(n, k) << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
void AOJ_DPL_5_E() {
    int n, k;
    cin >> n >> k;
    Combination com(k);
    cout << com.C(k, n) << "\n";
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F
void AOJ_DPL_5_F() {
    int n, k;
    cin >> n >> k;
    Combination com(n);
    cout << com.H(n - k, k) << "\n";
}

int main() {
    // yuki117();
    // AOJ_DPL_5_B();
    // AOJ_DPL_5_C();
    // AOJ_DPL_5_D();
    // AOJ_DPL_5_E();
    AOJ_DPL_5_F();
    return 0;
}