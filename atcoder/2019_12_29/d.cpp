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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;

    string t;
    cin >> t;

    // r, s, p の順
    vector < vector <int> > dp(n, vector <int>(3));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            if (t[i] == 'r') dp[i][2] += p;
            if (t[i] == 's') dp[i][0] += r;
            if (t[i] == 'p') dp[i][1] += s;
        } else {
            if (t[i] == 'r') {
                dp[i][0] = max(dp[i - k][1], dp[i - k][2]);
                dp[i][1] = max(dp[i - k][0], dp[i - k][2]);
                dp[i][2] = max(dp[i - k][0], dp[i - k][1]) + p;
            } else if (t[i] == 's') {
                dp[i][0] = max(dp[i - k][1], dp[i - k][2]) + r;
                dp[i][1] = max(dp[i - k][0], dp[i - k][2]);
                dp[i][2] = max(dp[i - k][0], dp[i - k][1]);
            } else if (t[i] == 'p') {
                dp[i][0] = max(dp[i - k][1], dp[i - k][2]);
                dp[i][1] = max(dp[i - k][0], dp[i - k][2]) + s;
                dp[i][2] = max(dp[i - k][0], dp[i - k][1]);
            }
        }

        if (i + k >= n) {
            ans += max(dp[i][0], max(dp[i][1], dp[i][2]));
        }
    }

    cout << ans << "\n";
    return 0;
}