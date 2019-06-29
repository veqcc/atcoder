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

ll dp[105][1000005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    int k;
    cin >> n >> k;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vector <int> vec;

    ll m = 1;
    while (m * m < n) {
        m++;
        vec.push_back(1);
    }

    while (m <= n) {
        ll tmp = n / m;
        vec.push_back(n / tmp - m + 1);
        m = n / tmp + 1;
    }

    int sz = vec.size();
    for (int i = 0; i < sz; i++) {
        dp[1][i] = vec[i];
        if (i) {
            dp[1][i] += dp[1][i-1];
            dp[1][i] %= MOD;
        }
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < sz; j++) {
            dp[i][j] = dp[i-1][sz - j - 1] * vec[j] % MOD;
            if (j) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[k][sz-1] << "\n";

    return 0;
}
