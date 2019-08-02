#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

// スターリング数は、写像12相のうち以下に相当する
//  ・玉の区別をする
//  ・箱の区別をしない
//  ・箱に入る玉の数は1つ以上

// 計算方法1: O(K log(N))
//  空箱の数で包除原理。k箱のうちi箱にのみ玉を入れるとすると↓
//  S(n,k) = (1/k!) * Σ(0<=i<=k) (-1)^(k-i) * {k,i} * i^n

// 計算方法2: O(NK)
//  S(n,k) = S(n-1,k-1) + kS(n-1,k)
//  この漸化式の考え方の方が応用範囲が広い

class Combination {
public:
    vector <ll> fac, inv, fiv;
    Combination(int N) : fac(N), inv(N), fiv(N) {
        fac[0] = inv[0] = fiv[0] = fac[1] = inv[1] = fiv[1] = 1;
        for (ll i = 2; i < N; i++) {
            fac[i] = fac[i - 1] * i % MOD; // n!
            inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
            fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
        }
    }
    ll C(ll n, ll k) {
        if (k < 0 || n < k) return 0;
        return fac[n] * fiv[k] % MOD * fiv[n - k] % MOD;
    }
};

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}

ll stirling_number(int n, int k) {
    Combination Com(k + 1);
    ll ret = 0;
    for (int i = 0; i <= k; i++) {
        ll add = Com.C(k, i) * pow_mod(i, n, MOD) % MOD;
        if ((k - i) & 1) add *= -1;
        ret = (ret + add + MOD) % MOD;
    }
    return ret * Com.fiv[k] % MOD;
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I&lang=jp
void AOJ_DPL_5_I() {
    int n, k;
    cin >> n >> k;
    cout << stirling_number(n, k) << "\n";
}

int main() {
    AOJ_DPL_5_I();
    return 0;
}
