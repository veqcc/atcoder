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
using namespace std;

int n;
ll x, t[5005];
vector <int> vec[5005];
ll dp[5005][5005];
// 最後にゲームを起動したのがt[i]
// 合計j回ゲームを起動している

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;

    for (int i = 1; i <= n; i++) cin >> t[i];
    t[0] = t[1] - x;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (t[j] - t[i] < x) continue;
            vec[i].push_back(j);
            if (j - 1 > i) vec[i].push_back(j-1);
            break;
        }
        if (vec[i].size() == 0) vec[i].push_back(n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k : vec[i]) {
                dp[k][j+1] = max(dp[k][j+1], dp[i][j] + min(x, t[k] - t[i]));
            }
        }
    }

    ll ret = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = j; i <= n; i++) {
            ret = max(ret, dp[i][j]);
        }
        cout << ret << '\n';
    }

    return 0;
}