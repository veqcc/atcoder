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

ll dp[100005][13];
// 下からi桁目まで見たときに、あまりがjであるような数

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    fill(dp[0], dp[n + 1], 0);
    dp[0][0] = 1;

    ll tmp = 1;
    for (int i = 1; i <= n; i++) {
        char c = s[n - i];

        // もらうDP
        if (c == '?') {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    int d = (k + tmp * j % 13) % 13;
                    dp[i][d] += dp[i - 1][k];
                    dp[i][d] %= MOD;
                }
            }
        } else {
            int j = c - '0';
            for (int k = 0; k < 13; k++) {
                int d = (k + tmp * j % 13) % 13;
                dp[i][d] += dp[i - 1][k];
                dp[i][d] %= MOD;
            }
        }

        tmp *= 10;
        tmp %= 13;
    }

    cout << dp[n][5] << "\n";
    return 0;
}