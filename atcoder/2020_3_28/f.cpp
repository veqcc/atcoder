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
const ll mod = 1000000007LL;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

class Combination {
public:
    vector <mint> fac, fiv;

    Combination(int N) : fac(N + 1), fiv(N + 1) {
        fac[0] = 1;
        for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i;
        fiv[N] = fac[N].inv();
        for (int i = N; i; i--) fiv[i - 1] = fiv[i] * i;
    }

    mint C(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[k] * fiv[n - k];
    }
};

Combination com(200005);

struct DP {
    mint dp;
    int sz;
    DP(ll dp = 1, int sz = 0) : dp(dp), sz(sz) {}
    DP& operator+= (const DP& a) {
        dp *= a.dp;
        dp *= com.C(sz + a.sz, sz);
        sz += a.sz;
        return *this;
    }
    DP operator- (const DP& a) const {
        DP res(*this);
        res.sz -= a.sz;
        res.dp /= com.C(res.sz + a.sz, res.sz);
        res.dp /= a.dp;
        return res;
    }
    DP addRoot() const {
        DP res(*this);
        res.sz++;
        return res;
    }
};

vector < vector<int> > edge(200005);
DP dp[200005];

void dfs1(int cur, int par = -1) {
    for  (int ch : edge[cur]) {
        if (ch == par) continue;
        dfs1(ch, cur);
        dp[cur] += dp[ch].addRoot();
    }
}

void dfs2(int cur, int par = -1) {
    for (int ch : edge[cur]) {
        if (ch == par) continue;
        DP d = dp[cur] - dp[ch].addRoot();
        dp[ch] += d.addRoot();
        dfs2(ch, cur);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Combination com(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs1(0);
    dfs2(0);

    for (int i = 0; i < n; i++) {
        cout << dp[i].addRoot().dp << endl;
    }

    return 0;
}