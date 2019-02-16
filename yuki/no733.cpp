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

int T, n, t[17], dp[1 << 17];

int main() {
    cin >> T >> n;
    for (int i = 0; i < n; i++) cin >> t[i];

    // initialize
    for (int i = 0; i < (1 << n); i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) if (i & (1 << j)) tmp += t[j];
        dp[i] = tmp <= T ? 1 : n;
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j > 0; j = (j-1)&i) {
            dp[i] = min(dp[i], dp[j] + dp[j ^ i]);
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}