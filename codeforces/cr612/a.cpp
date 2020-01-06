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

// i番目まで見た時に
// 奇数をj個、偶数をk個使っていて、
// i番目が偶数/奇数である時の
// 最小のcomplexity
int dp[105][105][105][2];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int even = n / 2, odd = n - even;
    vector <int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i]) {
            if (p[i] % 2 == 1) {
                odd--;
            } else {
                even--;
            }
        }
    }

    fill(dp[0][0][0], dp[n][odd + 1][even + 1] + 2, 100005);

    if (p[0] == 0) {
        dp[0][1][0][1] = 0;
        dp[0][0][1][0] = 0;
    } else {
        dp[0][0][0][p[0] % 2] = 0;
    }

    // 配るdp
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= odd; j++) {
            for (int k = 0; k <= even; k++) {
                if (p[i + 1] == 0) {
                    int tmp = min(dp[i][j][k][0] + 1, dp[i][j][k][1]);
                    dp[i + 1][j + 1][k][1] = min(tmp, dp[i + 1][j + 1][k][1]);

                    tmp = min(dp[i][j][k][0], dp[i][j][k][1] + 1);
                    dp[i + 1][j][k + 1][0] = min(tmp, dp[i + 1][j][k + 1][0]);
                } else {
                    if (p[i + 1] % 2 == 0) {
                        int tmp = min(dp[i][j][k][0], dp[i][j][k][1] + 1);
                        dp[i + 1][j][k][0] = min(tmp, dp[i + 1][j][k][0]);
                    } else {
                        int tmp = min(dp[i][j][k][0] + 1, dp[i][j][k][1]);
                        dp[i + 1][j][k][1] = min(tmp, dp[i + 1][j][k][1]);
                    }
                }
            }
        }
    }

    cout << min(dp[n - 1][odd][even][0], dp[n - 1][odd][even][1]) << "\n";
    return 0;
}