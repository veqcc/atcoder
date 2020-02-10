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

// 再帰
ll solve(string s, int k) {
    ll n = s.size();
    if (n < k) return 0;
    if (s[0] == '0') return solve(s.substr(1, n - 1), k);

    ll ans = 0;
    if (k == 1) {
        ans += s[0] - '0';
        ans += (n - 1) * 9;
    } else if (k == 2) {
        ans += (s[0] - '0' - 1) * 9 * (n - 1);
        ans += 81 * (n - 1) * (n - 2) / 2;
        ans += solve(s.substr(1, n - 1), 1);
    } else if (k == 3) {
        ans += (s[0] - '0' - 1) * 81 * (n - 1) * (n - 2) / 2;
        ans += 729 * (n - 1) * (n - 2) * (n - 3) / 6;
        ans += solve(s.substr(1, n - 1), 2);
    }

    return ans;
}

// 桁DP
int dp[105][2][5];
ll solve2(string s, int k) {
    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l <= k; l++) {
                for (int d = 0; d < 10; d++) {
                    int num = s[i] - '0';
                    if (j == 0 && d > num) continue;
                    dp[i + 1][j || d < num][d == 0 ? l : l + 1] += dp[i][j][l];
                }
            }
        }
    }
    return dp[n][0][k] + dp[n][1][k];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;
    cin >> s >> k;

    // cout << solve(s, k) << "\n";
    cout << solve2(s, k) << "\n";

    return 0;
}