#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define N 300005
typedef long long ll;
using namespace std;

ll M = 998244353;
ll n, a, b, k, i, ans=0;
ll inv[N], fac[N], fiv[N];

ll comb(ll p) {
    return fac[n] * fiv[p] % M * fiv[n-p] % M;
}

int main() {
    cin >> n >> a >> b >> k;

    inv[1]=fac[1]=fiv[1]=inv[0]=fac[0]=fiv[0]=1;
    for (i = 2; i <= n; i++) {
        fac[i] = fac[i-1] * i % M;
        inv[i] = inv[M%i] * (M-M/i) % M;
        fiv[i] = fiv[i-1] * inv[i] % M;
    }

    for (i = 0; i <= n; i++) {
        if ((k-i*a) % b == 0 && k >= i*a && (k-i*a)/b <= n) {
            ans += comb(i) * comb((k-i*a)/b) % M;
        }
    }

    cout << ans%M << endl;
    return 0;
}