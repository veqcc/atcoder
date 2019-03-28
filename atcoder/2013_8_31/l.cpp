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
const int INF = 1 << 30;

int dp[1005][1005];
// i番目の猫まで見たときに、
// j番目以降の猫がi番目の猫と距離1以内である
// ようなときの幸福度の最大値

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector < vector <int> > f(n+1, vector <int> (n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> f[i][j];
            f[i][j] += f[i][j-1];
        }
    }

    fill(dp[0], dp[1004], -INF);
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j];
            dp[i][j] += f[i][i] - f[i][j-1];
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }

        dp[i][i] = dp[i-1][i-1];
        dp[i][i] = max(dp[i][i], dp[i][i-1]);
    }

    cout << dp[n][n] * 2 << "\n";
    return 0;
}