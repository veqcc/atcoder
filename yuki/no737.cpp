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

const ll MOD = 1000000007LL;
ll dp[62][62][2];
ll pattern[62][62][2];

int main() {
    ll n;
    cin >> n;

    pattern[0][0][1] = 1;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            ll tmp = 1LL << (59 - i);
            (pattern[i+1][j][0] += pattern[i][j][0]) %= MOD;
            (pattern[i+1][j+1][0] += pattern[i][j][0]) %= MOD;
            if (n & tmp) {
                (pattern[i+1][j][0] += pattern[i][j][1]) %= MOD;
                (pattern[i+1][j+1][1] += pattern[i][j][1]) %= MOD;
            } else {
                (pattern[i+1][j][1] += pattern[i][j][1]) %= MOD;
            }
        }
    }

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            ll tmp = 1LL << (59 - i);
            (dp[i+1][j][0] += dp[i][j][0]) %= MOD;
            (dp[i+1][j+1][0] += dp[i][j][0] + tmp % MOD * pattern[i][j][0]) %= MOD;
            if (n & tmp) {
                (dp[i+1][j][0] += dp[i][j][1]) %= MOD;
                (dp[i+1][j+1][1] += dp[i][j][1] + tmp % MOD * pattern[i][j][1]) %= MOD;
            } else {
                (dp[i+1][j][1] += dp[i][j][1]) %= MOD;
            }
        }
    }

    ll ans = 0LL;
    for (int i = 0; i < 61; i++) {
        ans += (dp[60][i][0] + dp[60][i][1]) * i;
    }

    cout << ans % MOD << "\n";
    return 0;
}