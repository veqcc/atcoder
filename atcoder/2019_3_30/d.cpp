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

ll dp[205][100005];
// i番目まで見て、あまりがjである時の場合の数

int main() {
    int n, x;
    cin >> n >> x;

    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    sort(s, s+n, greater<int>());

    dp[0][x] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            (dp[i+1][j] += dp[i][j] * (n - i - 1)) %= MOD;
            (dp[i+1][j%s[i]] += dp[i][j]) %= MOD;
        }
    }

    ll ans = 0LL;
    for (int j = 1; j < s[n-1]; j++) {
        (ans += dp[n][j] * j) %= MOD;
    }

    cout << ans << "\n";
    return 0;
}