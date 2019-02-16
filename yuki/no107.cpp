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

int n, D[16], dp[1 << 16];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> D[i];

    dp[0] = 100;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] == 0) continue;

        int hp = 100; // 最大体力
        for (int j = 0; j < n; j++) {
            if (i & (1 << j) && D[j] < 0) hp += 100;
        }

        // 新たにjと戦う
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;

            int l = i | (1 << j);
            if (D[j]) {
                dp[l] = max(dp[l], min(hp, dp[i] + D[j]));
            } else if (dp[i] + D[j]) {
                dp[l] = max(dp[l], dp[i] + D[j]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}