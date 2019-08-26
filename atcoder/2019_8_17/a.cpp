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

int dp[200005][2];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    fill(dp[0], dp[n + 1], 0);

    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 1);
        if (i == 0 || (i > 0 && s[i - 1] != s[i])) {
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1);
        }

        dp[i + 2][1] = max(dp[i + 2][1], dp[i][0] + 1);
        if (i <= 1 || (i >= 2 && i < n - 1 && s.substr(i - 2, 2) != s.substr(i, 2))) {
            dp[i + 2][1] = max(dp[i + 2][1], dp[i][1] + 1);
        }
    }

    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}