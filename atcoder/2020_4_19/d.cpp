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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;

    Combination com(200005);
    mint ans = 0;
    for (ll i = k; i <= n + 1; i++) {
        ll mn = i * (i - 1) / 2;
        ll mx = i * (2 * n - i + 1) / 2;
        ans += mx - mn + 1;
    }

    cout << ans << "\n";
    return 0;
}