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

const int mod = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    bool a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int dp[1 << n];
    fill(dp, dp + (1 << n), 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n) - 1; j++) {
            if (i != __builtin_popcount(j)) continue;

            for (int k = 0; k < n; k++) {
                if (!(j & (1 << k)) && a[i][k]) {
                    dp[j | (1 << k)] += dp[j];
                    dp[j | (1 << k)] %= mod;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}