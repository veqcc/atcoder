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

    int n;
    cin >> n;

    vector <ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n % 2 == 0) {
        // i番目を使って、すでにj回skipしているような数
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        dp[1][0] = a[1];
        dp[2][1] = a[2];
        for (int i = 3; i <= n; i++) {
            dp[i][0] = dp[i - 2][0] + a[i];
            dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
        }

        cout << max(dp[n][1], dp[n - 1][0]) << endl;
    } else {
        vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
        dp[1][0] = a[1];
        dp[2][1] = a[2];
        dp[3][0] = a[1] + a[3];
        dp[3][2] = a[3];
        for (int i = 4; i <= n; i++) {
            dp[i][0] = dp[i - 2][0] + a[i];
            dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + a[i];
            dp[i][2] = max(max(dp[i - 2][2], dp[i - 3][1]), dp[i - 4][0]) + a[i];
        }

        cout << max(max(dp[n][2], dp[n - 1][1]), dp[n - 2][0]) << endl;
    }

    return 0;
}