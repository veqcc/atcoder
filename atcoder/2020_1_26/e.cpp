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

    int h, n;
    cin >> h >> n;

    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    // iこめの魔法までで、体力jを削るのに必要な魔力の最小値
    vector <int> dp(h + 10005, 1000000000);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            dp[j + a[i]] = min(dp[j + a[i]], dp[j] + b[i]);
        }
    }

    int mn = MOD;
    for (int j = h; j < h + 10005; j++) {
        mn = min(mn, dp[j]);
    }

    cout << mn << "\n";
    return 0;
}