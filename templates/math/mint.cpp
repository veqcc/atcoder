using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

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

// verified
//  https://atcoder.jp/contests/abc127/tasks/abc127_e
//  https://atcoder.jp/contests/abc127/submissions/11409157

// verified
//  https://atcoder.jp/contests/abc129/tasks/abc129_e
//  https://atcoder.jp/contests/abc129/submissions/11412931

// verified
//  https://atcoder.jp/contests/abc042/tasks/arc058_b
//  https://atcoder.jp/contests/abc042/submissions/11413430

// verified
//  https://atcoder.jp/contests/abc156/tasks/abc156_d
//  https://atcoder.jp/contests/abc156/submissions/11414198


int main {
};
