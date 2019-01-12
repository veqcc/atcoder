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

const ll inf = 1LL << 60;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n+1][n+1];
    fill(dp[0], dp[n+1], 0LL);

    for (int i = n; i >= 0; i--) {
        for (int j = i+2; j <= n; j++) {
            ll tmp = 0LL;
            dp[i][j] = inf;
            for (int k = i; k < j; k++) {
                tmp += a[k];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
            dp[i][j] += tmp;
        }
    }

    cout << dp[0][n] << "\n";
    return 0;
}