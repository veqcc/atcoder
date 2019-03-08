#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int dp[5005][5005];
// i人目までにjチーム作った時の最大人数 (i人目を含まない

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a, a+n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            int idx = lower_bound(a, a+n+1, a[i]+6) - a;
            dp[idx][j+1] = max(dp[idx][j+1], dp[i][j] + idx - i);
        }
    }

    int mx = 0;
    for (int i = 1; i <= k; i++) mx = max(mx, dp[n+1][i]);

    cout << mx << "\n";
    return 0;
}