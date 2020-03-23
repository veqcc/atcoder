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
const ll MOD = 998244353LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector < vector<ll> > dp(n + 1, vector<ll>(3005));

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = s; j; j--) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;

            if (j + a[i] <= s) {
                dp[i + 1][j + a[i]] += dp[i][j];
                dp[i + 1][j + a[i]] %= MOD;
            }
        }

        dp[i + 1][a[i]] += i + 1;
        dp[i + 1][a[i]] %= MOD;

        ans += dp[i + 1][s];
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}