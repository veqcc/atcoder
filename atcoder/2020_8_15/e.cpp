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
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<ll>> v(r + 1, vector<ll>(c + 1, 0));
    for (int i = 0; i < k; i++) {
        int rk, ck, vk;
        cin >> rk >> ck >> vk;
        v[--rk][--ck] = vk;
    }

    vector<vector<vector<ll>>> dp(r+1, vector<vector<ll>>(c+1, vector<ll>(5, 0)));
    dp[0][0][1] = v[0][0];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int l = 0; l < 4; l++) {
                // (i,j) -> (i,j+1)
                // dont pick
                dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l]);
                // pick
                dp[i][j + 1][l + 1] = max(dp[i][j + 1][l + 1], dp[i][j][l] + v[i][j + 1]);

                // (i,j) -> (i+1,j)
                // dont pick
                dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][l]);
                // pick
                dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][l] + v[i + 1][j]);
            }
        }
    }

    ll ans = 0;
    for (int l = 0; l < 4; l++) {
        ans = max(ans, dp[r - 1][c - 1][l]);
    }

    cout << ans << endl;
    return 0;
}