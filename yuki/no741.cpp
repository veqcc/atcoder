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
ll dp[1000000][10];
// i: 上からi桁目まで見て
// k: 直前の数
// の時の総数

int main() {
    int n;
    cin >> n;

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 10; k++) {
            for (int d = k; d < 10; d++) {
                (dp[i+1][d] += dp[i][k]) %= MOD;
            }
        }
    }

    ll ans = 0LL;
    for (int k = 0; k < 10; k++) {
        (ans += dp[n][k]) %= MOD;
    }

    cout << ans << "\n";
    return 0;
}