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

const int mod = 1000000007;
int dp[51][3001][2];
int c[51];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    k = min(k, 3000);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        while (a > 0) {
            c[i]++;
            a /= 2;
        }
    }

    for (int j = 0; j <= k; j++) {
        dp[0][j][0] = j < c[0] ? 1 : 0;
        dp[0][j][1] = j == c[0] ? 1 : 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = max(j - c[i] + 1, 0); l <= j; l++) {
                dp[i][j][0] += dp[i-1][l][0];
                dp[i][j][0] %= mod;
            }

            if (j - c[i] >= 0) {
                dp[i][j][1] += dp[i-1][j - c[i]][0];
            }

            for (int l = max(j - c[i], 0); l <= j; l++) {
                dp[i][j][1] += dp[i-1][l][1];
                dp[i][j][1] %= mod;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= k; j++) {
        ans += dp[n-1][j][1];
        ans %= mod;
    }

    ans += dp[n-1][k][0];
    ans %= mod;

    cout << ans << "\n";
    return 0;
}