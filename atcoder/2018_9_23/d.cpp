#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int i, n, m;
ll j, c, ans, M = 1000000007;
ll inv[10000000], fac[10000000], fiv[10000000];
ll combination(ll k) {
    return fac[n+k-1] * fiv[k] % M * fiv[n-1] % M;
}

int main() {
    cin >> n >> m;

    inv[1]=fac[1]=fiv[1]=inv[0]=fac[0]=fiv[0]=1;
    for (ll j = 2; j < 10000000; j++) {
        fac[j] = fac[j-1] * j % M; // n!
        inv[j] = inv[M%j] * (M-M/j) % M; // n^-1
        fiv[j] = fiv[j-1] * inv[j] % M; // (n!)^-1
    }

    i = 2;
    ans = 1LL;
    while (m > 1) {
        if (m % i == 0) {
            c = 0LL;
            while (m % i == 0) {
                c++; m /= i;
            }
            ans = ans * combination(c) % M;
        } else {
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}