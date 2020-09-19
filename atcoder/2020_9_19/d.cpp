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
const ll MOD = 998244353;

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

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n), r(n);
    for (int i = 0; i < k; i++) {
        cin >> l[i] >> r[i];
        r[i]++;
    }

    vector<mint> dp(2 * n, 0);
    dp[1] = 1;
    dp[2] = MOD - 1;

    for (int i = 1; i < n; i++) {
        dp[i + 1] += dp[i];
        for (int j = 0; j < k; j++) {
            dp[i + l[j]] += dp[i];
            dp[i + r[j]] -= dp[i];
        }
    }

    cout << dp[n] << endl;
    return 0;
}