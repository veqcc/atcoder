#include <algorithm>
#include <iostream>
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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    ll b, dp[n + 1];
    dp[0] = 0LL;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        dp[i] = dp[i - 1] + b;
        if (i >= k) {
            dp[i] = max(dp[i - k], dp[i]);
            dp[i - k + 1] = max(dp[i - k + 1], dp[i - k]);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}