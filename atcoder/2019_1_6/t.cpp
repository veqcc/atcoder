#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int MOD = 1e9+7;

int dp[3005][3005];
// i番目まで見た時に、i番目より小さい数字がj個残っているような場合の数

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) dp[0][i] = 1;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (s[i] == '<') {
                (dp[i+1][j] += dp[i][j]) %= MOD;
                (dp[i+1][n-i] += MOD - dp[i][j]) %= MOD;
            } else {
                (dp[i+1][0] += dp[i][j]) %= MOD;
                (dp[i+1][j] += MOD - dp[i][j]) %= MOD;
            }
        }

        for (int j = 1; j < n-i; j++) {
            (dp[i+1][j] += dp[i+1][j-1]) %= MOD;
        }
    }

    cout << dp[n-1][0] << "\n";
    return 0;
}