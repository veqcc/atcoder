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

class Solution {
    const int INF = 1e9 + 5;
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        int m = arr2.size();

        vector <vector<int>> dp(n + 1, vector<int>(m + 1, INF));

        dp[1][m] = 0;
        for (int i = 0; i < m; i++) dp[1][i] = 1;

        for (int i = 1; i < n; i++) {
            if (arr1[i - 1] < arr1[i]) {
                dp[i + 1][m] = min(dp[i + 1][m], dp[i][m]);
            }

            for (int j = 0; j < m; j++) {
                if (arr1[i - 1] < arr2[j]) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][m] + 1);
                }

                if (arr2[j] < arr1[i]) {
                    dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
                }
            }

            int mn = INF;
            for (int j = 0; j < m; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], mn + 1);
                mn = min(mn, dp[i][j]);
            }
        }

        int ans = *min_element(dp[n].begin(), dp[n].end());
        return ans < INF ? ans : -1;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a1(n), a2(m);
    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < m; i++) cin >> a2[i];

    Solution s;
    cout << s.makeArrayIncreasing(a1, a2) << "\n";
    return 0;
}