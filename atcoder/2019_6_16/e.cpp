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

ll dp[2005][2005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int s[n], t[m];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 0; i <= m; i++) dp[0][i] = 1;

    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                tmp = (tmp + dp[i][j]) % MOD;
            }

            dp[i+1][j+1] = (dp[i][j+1] + tmp) % MOD;
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}