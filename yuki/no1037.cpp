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
const ll MX = 1LL << 60;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, V, l;
    cin >> n >> V >> l;

    vector <ll> x(n + 1, 0), v(n), w(n);
    for (int i = 0; i < n; i++) cin >> x[i + 1] >> v[i] >> w[i];

    // dp[i][j]: i番目のガソスタまで行って、燃料がjの時の最小費用
    vector < vector <ll> > dp(n + 1, vector<ll>(V + 1, MX));
    dp[0][V] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = x[i + 1] - x[i]; j <= V; j++) {
            ll nxt_v = j - (x[i + 1] - x[i]);
            dp[i + 1][nxt_v] = min(dp[i + 1][nxt_v], dp[i][j]);

            nxt_v = min(V, nxt_v + v[i]);
            dp[i + 1][nxt_v] = min(dp[i + 1][nxt_v], dp[i][j] + w[i]);
        }
    }

    ll ans = 1LL << 60;
    for (int j = l - x[n]; j <= V; j++) {
        if (dp[n][j] < MX) {
            ans = min(ans, dp[n][j]);
        }
    }

    cout << (ans == MX ? -1 : ans) << "\n";
    return 0;
}