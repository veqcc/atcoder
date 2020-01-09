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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    int diff[h][w];
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> diff[i][j];
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        int b;
        cin >> b;
        diff[i][j] = abs(diff[i][j] - b);
    }

    int center = (h + w - 2) * 80;
    bool dp[h][w][center * 2 + 1];
    fill(dp[0][0], dp[h - 1][w - 1] + center * 2 + 1, 0);
    dp[0][0][center + diff[0][0]] = dp[0][0][center - diff[0][0]] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k <= center * 2; k++) {
                if (i && dp[i - 1][j][k]) {
                    dp[i][j][k + diff[i][j]] = 1;
                    dp[i][j][k - diff[i][j]] = 1;
                }
                if (j && dp[i][j - 1][k]) {
                    dp[i][j][k + diff[i][j]] = 1;
                    dp[i][j][k - diff[i][j]] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= center; i++) {
        if (dp[h - 1][w - 1][center + i]) {
            ans = i;
            break;
        }
        if (dp[h - 1][w - 1][center - i]) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}