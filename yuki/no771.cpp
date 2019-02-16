#include <algorithm>
#include <iostream>
#include <iomanip>
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

int n;
int a[20], b[20], dp[1 << 20][20];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // dp[i][j] : i -> どれを使ったか、j -> 直前に何を使ったか
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!(i & (1 << j))) continue;
                if (i & (1 << k)) continue;

                int l = i | (1 << k);
                int mx = max(dp[i][j], b[j] - a[j] + a[k]);
                dp[l][k] = dp[l][k] ? min(dp[l][k], mx) : mx;
            }
        }
    }

    int mn = 2000;
    for (int i = 0; i < n; i++) {
        mn = min(mn, dp[(1 << n) - 1][i]);
    }

    cout << mn << "\n";
    return 0;
}