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
const ll MOD = 1e9 + 7;

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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

typedef pair <ll, ll> P;

int main() {
    int n;
    cin >> n;

    int all_zero = 0;
    map<P, ll> mp;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            all_zero++;
        } else {
            ll g = gcd(abs(a), abs(b));
            a /= g;
            b /= g;
            mp[{a, b}]++;
        }
    }

    mint ans = 1;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        ll a = itr->first.first;
        ll b = itr->first.second;
        ll num = itr->second + mp[{-a, -b}];
        ll pair_num = mp[{-b, a}] + mp[{b, -a}];

        mp[{a, b}] = 0;
        mp[{-a, -b}] = 0;
        mp[{-b, a}] = 0;
        mp[{b, -a}] = 0;

        mint tmp1 = 2, tmp2 = 2;
        ans *= (tmp1.pow(num) + tmp2.pow(pair_num) - 1);
    }

    cout << ans + all_zero - 1 << endl;
    return 0;
}