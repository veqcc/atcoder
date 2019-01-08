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
const int INF = 1 << 30;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp[n+1][3];
    fill(dp[0], dp[n]+3, INF);
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i-1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i-1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i-1];
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
    return 0;
}