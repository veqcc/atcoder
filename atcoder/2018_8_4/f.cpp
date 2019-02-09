#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int M = 998244353;
int n, c[1005];
ll a, dp[1005][1005], inv[1005], fac[1005], fiv[1005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        c[a]++;
    }

    inv[1]=fac[1]=fiv[1]=inv[0]=fac[0]=fiv[0]=1;
    for (ll i = 2; i <= n; i++) {
        fac[i] = fac[i-1] * i % M; // n!
        inv[i] = inv[M%i] * (M-M/i) % M; // n^-1
        fiv[i] = fiv[i-1] * inv[i] % M; // (n!)^-1
    }

    dp[n+1][0] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= n; j++) {
            if (dp[i+1][j] == 0) continue;

            int remain = j + c[i];
            for (int k = 0; k <= remain/i; k++) {
                // (i!)^-k を計算したい
                int t = k;
                ll x = fiv[i], y = 1;
                while (t > 0) {
                    if (t % 2 == 1) y = x * y % M;
                    x = x * x % M;
                    t >>= 1;
                }

                ll tmp = fac[remain] * fiv[remain - k*i] % M * fiv[k] % M * y % M;
                dp[i][remain - k*i] = (dp[i][remain - k*i] + dp[i+1][j] * tmp % M) % M;
            }
        }
    }

    cout << dp[1][0] << "\n";
    return 0;
}