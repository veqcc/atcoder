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

ll dp[100005][2];
// i桁目まで見て、すでに「未満」 が達成されているか

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string L;
    cin >> L;

    int n = L.size();

    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        if (L[i] == '0') {
            dp[i+1][0] = 3 * dp[i][0] % MOD;
            dp[i+1][1] = dp[i][1];
        } else {
            dp[i+1][0] = (3 * dp[i][0] + dp[i][1]) % MOD;
            dp[i+1][1] = 2 * dp[i][1] % MOD;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    return 0;
}