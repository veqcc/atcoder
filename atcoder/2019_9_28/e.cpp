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

    vector<int> cost(m), vec(m);
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> cost[i] >> b;
        for (int j = 0; j < b; j++) {
            cin >> c;
            c--;
            vec[i] += 1 << c;
        }
    }

    // i番目の鍵までのなかで、箱の組み合わせjを開けるのに必要な最小コスト
    vector <vector<int>> dp(m + 1, vector<int>(1 << n, MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);

            int use = j | vec[i - 1];
            dp[i][use] = min(dp[i][use], dp[i - 1][j] + cost[i - 1]);
        }
    }

    if (dp[m][(1 << n) - 1] == MAX) {
        cout << -1 << '\n';
    } else {
        cout << dp[m][(1 << n) - 1] << '\n';
    }

    return 0;
}