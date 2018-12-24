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

int n, m;
char c[2005][2005];
ll dp[2005][2005][4]; // 上下左右

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            c[i][j] = s[j];
        }
    }

    // 上 & 左
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && c[i-1][j] == '.') {
                dp[i][j][0] += dp[i-1][j][0] + 1;
            }
            if (j > 0 && c[i][j-1] == '.') {
                dp[i][j][2] += dp[i][j-1][2] + 1;
            }
        }
    }

    // 下 & 右
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (i < n-1 && c[i+1][j] == '.') {
                dp[i][j][1] += dp[i+1][j][1] + 1;
            }
            if (j < m-1 && c[i][j+1] == '.') {
                dp[i][j][3] += dp[i][j+1][3] + 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.') {
                ans += (dp[i][j][0] + dp[i][j][1]) * (dp[i][j][2] + dp[i][j][3]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}