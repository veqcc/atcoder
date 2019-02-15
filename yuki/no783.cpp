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
typedef unsigned int uint;
using namespace std;

int n, C, l[55], w[55], dp[55][55][55];
map <int, int> mp;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> C;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            for (int k = 0; k < 55; k++) {
                dp[i][j][k] = - (1 << 30);
            }
        }
    }

    int ans = 0;
    dp[0][0][0] = 0;
    for (int c = 1; c <= C; c++) { // cost
        for (int q = 0; q <= n; q++) { // 2こ前
            for (int p = 0; p <= n; p++) { // 1こ前
                for (int i = 1; i <= n; i++) { // 今加えようとしてるもの
                    if (l[p] == l[i] || l[i] == l[q]) continue;
                    if (q && p && l[q] < l[p] && l[p] < l[i]) continue;
                    if (q && p && l[q] > l[p] && l[p] > l[i]) continue;
                    if (c < w[i]) continue;
                    if (dp[c - w[i]][q][p] < 0) continue;
                    dp[c][p][i] = max(dp[c][p][i], dp[c - w[i]][q][p] + l[i]);
                    if (q && p) ans = max(ans, dp[c][p][i]);
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}