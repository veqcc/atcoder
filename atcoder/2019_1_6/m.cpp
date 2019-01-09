#include <algorithm>
#include <iostream>
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

ll mod = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n+1][k+1];
    fill(dp[0], dp[n]+k+1, 0LL);
    dp[0][0] = 1LL;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1LL;
        for (int j = 1; j <= k; j++) {
            if (j <= a[i-1]) {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
            } else {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j - a[i-1] - 1]) % mod;
            }
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}
