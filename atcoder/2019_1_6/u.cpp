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

ll dp[1 << 16];
ll cost[1 << 16];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << i) && mask & (1 << j)) {
                    cost[mask] += a[i][j];
                }
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int mask2 = mask; mask2 > 0; mask2 = (mask2 - 1) & mask) {
            dp[mask] = max(dp[mask], dp[mask ^ mask2] + cost[mask2]);
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}