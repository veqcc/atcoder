#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

// ベル数は、写像12相のうち以下に相当する
//  ・玉の区別をする
//  ・箱の区別をしない
//  ・箱に入る玉の数に制限はない

// 単純に考えると、スターリング数をS(n,k)として、
// B(n,k) = S(n,0) + S(n,1) + ... + S(n,k)

// 計算方法: O(min(N,K)lon(N))
//  B(n,k) = Σ(0<=i<=k) i^n / i! * (Σ(0<=j<=k-i) (-1)^j / j!)
//  Σ(0<=j<=k-i) (-1)^j / j! が事前計算可能なので、O(min(N,K)lon(N))になる
//  cf: https://qiita.com/drken/items/f2ea4b58b0d21621bd51

// B(n,n) = B(n) をベル数と呼ぶこともある。以下の漸化式でO(N^2)
// B(n+1) = Σ(0<=i<=n) nCi * B(n) : 要素n+1と同じグループにならない要素数をiとするとわかる

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
};

ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) { if (pow & 1) prod = prod * num % mod; num = num * num % mod; pow >>= 1; }
    return prod;
}

ll bell_number(int n, int k) {
    if (n == 0) return 1;
    k = min(k, n);
    Combination com(k);
    ll ret = 0;
    vector <ll> pre(k + 1, 1);
    for (int i = 1; i <= k; i++) {
        if (i & 1) pre[i] = pre[i - 1] - com.fiv[i];
        else pre[i] = pre[i - 1] + com.fiv[i];
    }
    for (int i = 1; i <= k; i++) {
        ret += pow_mod(i, n, MOD) * com.fiv[i] % MOD * pre[k - i];
        ret %= MOD;
    }
    return ret;
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
void AOJ_DPL_5_G() {
    int n, k;
    cin >> n >> k;
    cout << bell_number(n, k) << '\n';
}

int main() {
    AOJ_DPL_5_G();
    return 0;
}