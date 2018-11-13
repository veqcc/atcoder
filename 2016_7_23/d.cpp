#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll M = 1000000007;
ll inv[200001], fac[200001], fiv[200001];
ll H, W, A, B;
ll combination(ll h, ll w) {
    return fac[h+w] * fiv[h] % M * fiv[w] % M;
}

int main() {
    cin >> H >> W >> A >> B;

    inv[1]=fac[1]=fiv[1]=inv[0]=fac[0]=fiv[0]=1;
    for (ll i = 2; i <= H+W; i++) {
        fac[i] = fac[i-1] * i % M; // n!
        inv[i] = inv[M%i] * (M-M/i) % M; // n^-1
        fiv[i] = fiv[i-1] * inv[i] % M; // (n!)^-1
    }

    ll h = H - A;
    ll w = B + 1;
    ll ans = 0LL;
    while (h >= 1 && w <= W) {
        ans  = (ans + (combination(h-1, w-1) * combination(H-h, W-w) % M)) % M;
        h--;
        w++;
    }

    cout << ans << endl;
    return 0;
}