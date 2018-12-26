#include <algorithm>
#include <iostream>
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

const int inf = 1 << 30;
const string yahoo = "yahoo";

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int len = s.length();
    int dp[len+1][5];
    fill(dp[0], dp[len+1], inf);
    dp[0][0] = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 11; j++) {
            int cur = j % 5;
            int nxt = (j + 1) % 5;
            int cost = s[i] == yahoo[cur] ? 0 : 1;
            dp[i+1][nxt] = min({
                dp[i][cur] + cost,
                dp[i][nxt] + 1,
                dp[i+1][cur] + 1
            });
        }
    }

    cout << dp[len][0] << "\n";
    return 0;
}