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

    char s[h][w];
    for (int i = 0; i < h; i++) cin >> s[i];

    int dp[h][w];
    fill(dp[0], dp[h - 1] + w, 0);

    if (s[0][0] == '#') dp[0][0] = 1;

    for (int j = 1; j < w; j++) {
        dp[0][j] = dp[0][j - 1];
        if (s[0][j] != s[0][j - 1]) dp[0][j]++;
    }

    for (int i = 1; i < h; i++) {
        dp[i][0] = dp[i - 1][0];
        if (s[i][0] != s[i - 1][0]) dp[i][0]++;

        for (int j = 1; j < w; j++) {
            int tmp1 = dp[i - 1][j];
            if (s[i][j] != s[i - 1][j]) tmp1++;

            int tmp2 = dp[i][j - 1];
            if (s[i][j] != s[i][j - 1]) tmp2++;

            dp[i][j] = min(tmp1, tmp2);
        }
    }

    cout << (dp[h - 1][w - 1] + 1) / 2 << "\n";
    return 0;
}