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
typedef pair <char, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int white[n][n+1]; // 白iより前に、i+1以上の白とj以上の黒がいくつあるか
    int black[n][n+1]; // 黒iより前に、i+1以上の黒とj以上の白がいくつあるか

    vector <int> white_count(n, 0);
    vector <int> black_count(n, 0);

    for (int i = 0; i < 2 * n; i++) {
        char color; int idx;
        cin >> color >> idx; idx--;

        // 累積和
        vector <int> white_sum(n + 1, 0); // j以上の白がいくつあるか
        vector <int> black_sum(n + 1, 0); // j以上の黒がいくつあるか
        for (int j = n-1; j >= 0; j--) {
            white_sum[j] = white_count[j] + white_sum[j+1];
            black_sum[j] = black_count[j] + black_sum[j+1];
        }

        for (int j = 0; j <= n; j++) {
            if (color == 'W') white[idx][j] = black_sum[j] + white_sum[idx+1];
            if (color == 'B') black[idx][j] = white_sum[j] + black_sum[idx+1];
        }

        if (color == 'W') white_count[idx]++;
        if (color == 'B') black_count[idx]++;
    }

    int dp[n+1][n+1]; // 白をi個黒をj個置いた時の転倒数の最小値
    fill(dp[0], dp[n+1], (1<<30));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i < n) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + white[i][j]);
            if (j < n) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + black[j][i]);
        }
    }

    cout << dp[n][n] << "\n";
    return 0;
}