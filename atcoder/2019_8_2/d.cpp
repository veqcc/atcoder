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

ll dp[1005][1005][3];
// i桁目まで考えた時、出力をj文字読んでいて、3で割った余りがkであるような場合の数

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <string> s(n);
    for (int i = 0; i < m; i++) cin >> s[i];

    fill(dp[0][0], dp[0][0] + 3, 0LL);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[j] == "FizzBuzz") {
                if (i) dp[i + 1][j + 1][0] += dp[i][j][0] + dp[i][j][1];
            } else if (s[j] == "Fizz") {
                dp[i + 1][j + 1][0] += 3 * dp[i][j][0] + 2 * dp[i][j][1] + 3 * dp[i][j][2];
            } else if (s[j] == "Buzz") {
                dp[i + 1][j + 1][1] += dp[i][j][1] + dp[i][j][2];
                dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][2];
            }

            dp[i + 1][j][1] += 3 * dp[i][j][0] + 3 * dp[i][j][1] + 2 * dp[i][j][2];
            dp[i + 1][j][2] += 2 * dp[i][j][0] + 3 * dp[i][j][1] + 3 * dp[i][j][2];

            for (int k = 0; k < 3; k++) {
                dp[i + 1][j + 1][k] %= MOD;
                dp[i + 1][j][k] %= MOD;
            }
        }
    }

    cout << (dp[n][m][0] + dp[n][m][1] + dp[n][m][2]) % MOD << "\n";
    return 0;
}