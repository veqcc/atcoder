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

ll dp[1000005];
// i番目の駅に止まるような組み合わせ の累積和 の累積和

int main() {
    int n, k;
    cin >> n >> k;

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 2];
        if (i - k > 1) dp[i] -= dp[i - k - 1];
        if (i < k) dp[i] += 1;

        dp[i] += 2 * dp[i - 1] - dp[i - 2];
        dp[i] = (dp[i] + 2 * MOD) % MOD;
    }

    cout << (dp[n] - 2 * dp[n - 1] + dp[n - 2] + 2 * MOD) % MOD  << "\n";
    return 0;
}