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

const ll MOD = 1000000007LL;
ll dp[3005][3005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int l[m], r[m];
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }

    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        vector <ll> vec(n);
        for (int j = 0; j < n; j++) {
            vec[j] = dp[i][j];
            if (j) vec[j] += vec[j-1];
            vec[j] %= MOD;
        }

        for (int j = 0; j < m; j++) {
            ll cnt = vec[r[j]];
            if (l[j]) cnt -= vec[l[j] - 1];
            cnt = (cnt + MOD) % MOD;

            (dp[i+1][l[j]] += cnt) %= MOD;
            (dp[i+1][r[j] + 1] += MOD - cnt) %= MOD;
        }

        for (int j = 1; j < n; j++) {
            (dp[i+1][j] += dp[i+1][j-1]) %= MOD;
        }
    }

    cout << dp[k][n-1] << "\n";
    return 0;
}