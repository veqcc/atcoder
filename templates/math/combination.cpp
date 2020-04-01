#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

template <ll mod> class ModInt {
    ll a;
public:
    constexpr ModInt(const ll a = 0) noexcept : a((a % mod + mod) % mod) {}
    constexpr ll &value() noexcept { return a; }
    constexpr ModInt operator + (const ModInt &rhs) const noexcept { return ModInt(*this) += rhs; }
    constexpr ModInt operator - (const ModInt &rhs) const noexcept { return ModInt(*this) -= rhs; }
    constexpr ModInt operator * (const ModInt &rhs) const noexcept { return ModInt(*this) *= rhs; }
    constexpr ModInt operator / (const ModInt &rhs) const noexcept { return ModInt(*this) /= rhs; }
    constexpr ModInt &operator += (const ModInt &rhs) noexcept {
        a += rhs.a;
        if (a >= mod) a -= mod;
        return *this;
    }
    constexpr ModInt &operator -= (const ModInt &rhs) noexcept {
        a += mod - rhs.a;
        if (a >= mod) a -= mod;
        return *this;
    }
    constexpr ModInt &operator *= (const ModInt &rhs) noexcept {
        a = a * rhs.a % mod;
        return *this;
    }
    constexpr ModInt pow(ll t) const noexcept {
        if (t == 0) return 1;
        auto ret = pow(t >> 1);
        ret *= ret;
        if (t & 1) ret *= *this;
        return ret;
    }
    constexpr ModInt inv() const noexcept { return pow(mod - 2); }
    constexpr ModInt operator /=(const ModInt &rhs) { return (*this) *= rhs.inv(); }
    constexpr bool operator == (const ModInt &rhs) const noexcept { return this->a == rhs.a; }
    constexpr bool operator != (const ModInt &rhs) const noexcept { return this->a != rhs.a; }
    friend constexpr ostream &operator << (ostream &os, const ModInt &rhs) noexcept { return os << rhs.a; }
    friend constexpr istream &operator >> (istream &is, ModInt &rhs) {
        is >> rhs.a;
        return is;
    }
};
using mint = ModInt<MOD>;

class Combination {
public:
    vector <mint> fac, inv, fiv;
    Combination(int N) : fac(N + 1), inv(N + 1), fiv(N + 1) {
        fac[0] = inv[0] = fiv[0] = fac[1] = inv[1] = fiv[1] = 1;
        for (ll i = 2; i <= N; i++) {
            fac[i] = fac[i - 1] * i; // n!
            inv[i] = inv[MOD % i] * (MOD - MOD / i); // n^-1
            fiv[i] = fiv[i - 1] * inv[i]; // (n!)^-1
        }
    }
    mint C(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[k] * fiv[n - k];
    }
    mint P(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[n - k];
    }
    mint H(ll n, ll k) {
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
void AOJ_DPL_5_C() {
    int n, k;
    cin >> n >> k;
    Combination com(k);
    mint ans = 0;
    for (int i = 0; i < k; i++) {
        mint sgn = i % 2 == 0 ? 1 : -1;
        ans += sgn * com.C(k, k - i) * ((mint)(k - i)).pow(n);
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
    yuki117();
    // AOJ_DPL_5_B();
    // AOJ_DPL_5_C();
    // AOJ_DPL_5_D();
    // AOJ_DPL_5_E();
    // AOJ_DPL_5_F();
    return 0;
}