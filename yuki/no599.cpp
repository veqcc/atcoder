#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
using ull = unsigned long long;

const ll MOD = 1e9+7LL;
ll dp[10005]; // 文字列S[i:sz-i]を回文かい分解する組み合わせ数
bool checked[10005];
vector <int> z[10005];

random_device rnd;
mt19937 mt(rnd());

ll mod_pow(ll x, ll n, ll mod) {
    if (n <= 0) return 1;
    ll tmp = mod_pow(x, n / 2, mod);
    return tmp * tmp % mod * (n % 2 ? x : 1) % mod;
}

bool is_prime(ll n, int times = 50) {
    if (n == 2) return true;
    if (n % 2 == 0 || n < 2) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    while (times--) {
        ll a = rnd() % (n - 2) + 1;
        ll t = d;
        ll y = mod_pow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) { y = y * y % n; t *= 2; }
        if (y != n - 1 && t % 2 == 0) return false;
    }
    return true;
}

ll gen_prime() {
    while (1) {
        ll n = mt();
        if (n == 1) continue;
        if (is_prime(n)) return n;
    }
}

class RollingHash {
public:
    vector <ull> hash, pows;
    ull base, mod;
    RollingHash() { base = gen_prime(); mod = gen_prime(); }
    void init(const string& S) {
        hash.resize(S.size() + 1); pows.resize(S.size() + 1);
        pows[0] = 1;
        for (int i = 0; i < S.size(); i++) {
            pows[i+1] = pows[i] * base % mod;
            hash[i+1] = (hash[i] * base % mod + S[i]) % mod;
        }
    }
    ull get(int l, int r) { // [l, r)
        if (l > r) return -1;
        ull ret = (hash[r] + mod - hash[l] * pows[r - l] % mod) % mod;
        return ret;
    }
};


RollingHash rh;

ll rec2(int l, int r) {
    if (r < l) return 1;
    if (checked[l]) return dp[l];

    ll ret = 1;
    int left = l+1, right = r-1;
    while (left <= right) {
        if (rh.get(l, left) == rh.get(right, r)) (ret += rec2(left, right)) %= MOD;
        left++; right--;
    }

    checked[l] = true;
    return dp[l] = ret;
}

vector <int> ZAlgorithm(const string& S) {
    int sz = S.size();
    vector <int> ret(sz);
    ret[0] = sz;
    int i = 1, j = 0;
    while (i < sz) {
        while (i+j < sz && S[j] == S[i+j]) j++;
        ret[i] = j;
        if (j == 0) { i++; continue; }
        int k = 1;
        while (i+k < sz && k+ret[k] < j) ret[i+k] = ret[k], k++;
        i += k; j -= k;
    }
    return ret;
}

ll rec(int l, int r) {
    if (r < l) return 1;
    if (checked[l]) return dp[l];

    ll ret = 1;
    int left = l, right = r;
    while (left < right) {
        if (z[l][right - l] == left - l + 1) (ret += rec(left+1, right-1)) %= MOD;
        left++; right--;
    }

    checked[l] = true;
    return dp[l] = ret;
}

int main() {
    string S;
    cin >> S;

    int sz = S.size();
    for (int i = 0; i * 2 < sz; i++) z[i] = ZAlgorithm(S.substr(i, sz - i * 2));
    ll z_ans = rec(0, sz-1);

    fill(dp, dp+sz, 0);
    fill(checked, checked+sz, false);
    rh.init(S);
    ll r_ans = rec2(0, sz);

    if (z_ans == r_ans) {
        cout << z_ans << "\n";
    } else {
        cout << z_ans << " " << r_ans << "\n";
    }

    return 0;
}