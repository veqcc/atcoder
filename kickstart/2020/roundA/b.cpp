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

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, k, p;
        cin >> n >> k >> p;

        vector < vector <int> > beauty(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cin >> beauty[i][j];
                if (j) beauty[i][j] += beauty[i][j - 1];
            }
        }

        // iスタック目まで見て、j個すでに取ったときの最大値
        vector < vector<int> > dp(n + 1, vector<int>(p + 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p + 1; j++) {
                // iスタック目で取らない
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                // iスタック目でl番目まで取る
                for (int l = 0; l < k; l++) {
                    if (j + l + 1 <= p) {
                        dp[i + 1][j + l + 1] = max(dp[i + 1][j + l + 1], dp[i][j] + beauty[i][l]);
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << dp[n][p] << '\n';
    }

    return 0;
}