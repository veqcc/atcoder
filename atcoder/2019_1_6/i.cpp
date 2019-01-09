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

    int n;
    cin >> n;
    double p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    double dp[n+1][n+1];
    fill(dp[0], dp[n]+n+1, 0.0);
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] * (1 - p[i-1]);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] * p[i-1] + dp[i-1][j] * (1.0 - p[i-1]);
        }
    }

    double ret = 0.0;
    for (int i = n/2+1; i <= n; i++) {
        ret += dp[n][i];
    }

    cout.precision(10);
    cout << ret << "\n";
    return 0;
}