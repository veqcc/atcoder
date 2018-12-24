#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
ll M = 1000000007;
ll dp[605], ndp[605];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    ll ans = 0;
    fill(ndp, ndp+605, 0LL);

    for (int i = 0; i < n+10; i++) {
        ans += dp[1];
        int x = 0;
        if (i < n) cin >> x;
        if (x >= 1) ans++;
        ans %= M;
        for (int j = 0; j < 300; j++) {
            ndp[j] = 0;
            for (int k = 0; k <= x && k <= 2*j; k++) {
                ndp[j] = (ndp[j] + dp[2*j-k]) % M;
            }
        }
        for (int j = 0; j < 300; j++) {
            dp[j] = ndp[j];
        }
    }

    cout << ans << endl;
    return 0;
}