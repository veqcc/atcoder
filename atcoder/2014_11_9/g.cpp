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
const int MAX = 1 << 30;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(m));
    dp[0][0] = 1;

    int ans = MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] = 1;
                if (j + a[i] >= m) {
                    ans = min(ans, j + a[i]);
                } else {
                    dp[i + 1][j + a[i]] = 1;
                }
            }
        }
    }

    cout << (ans == MAX ? -1 : ans) << "\n";
    return 0;
}