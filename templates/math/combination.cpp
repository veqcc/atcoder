#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

class Combination {
    int N;
    vector <ll> fac, inv, fiv;

    void init() {
        fac[0] = inv[0] = fiv[0] = 1;
        fac[1] = inv[1] = fiv[1] = 1;
        for (ll i = 2; i < N; i++) {
            fac[i] = fac[i - 1] * i % MOD; // n!
            inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; // n^-1
            fiv[i] = fiv[i - 1] * inv[i] % MOD; // (n!)^-1
        }
    }

public:
    Combination(int N) : N(N), fac(N), inv(N), fiv(N) { init(); }

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
        return C(n + k - 1, k);
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
        while (s[i] != ',') {
            n *= 10;
            n += s[i++] - '0';
        }
        i++;
        while (s[i] != ')') {
            k *= 10;
            k += s[i++] - '0';
        }
        if (s[0] == 'C') cout << com.C(n, k) << "\n";
        else if (s[0] == 'P') cout << com.P(n, k) << "\n";
        else cout << com.H(n, k) << "\n";
    }
}

int main() {
    yuki117();
    return 0;
}