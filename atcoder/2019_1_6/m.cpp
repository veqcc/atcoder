#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <vector<ll>> dp(n + 1, vector<ll>(k + 1, 0LL));
    // dp[i][j]: i人にちょうどj個の飴を配る方法が何通りあるか

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1LL;
        for (int j = 1; j <= k; j++) {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
            if (j > a[i]) dp[i][j] -= dp[i - 1][j - a[i] - 1];
            dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}