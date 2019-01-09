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

int mod = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    char a[H][W];
    for (int i = 0; i < H; i++) {
        cin >> a[i];
    }

    ll dp[H][W];
    fill(dp[0], dp[H-1]+W, 0);
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '.') {
                if (i > 0 && a[i-1][j] == '.') {
                    dp[i][j] += dp[i-1][j];
                }
                if (j > 0 && a[i][j-1] == '.') {
                    dp[i][j] += dp[i][j-1];
                }
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[H-1][W-1] << "\n";
    return 0;
}