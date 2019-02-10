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

const ll mod = 998244353LL;
ll red[4005], blue[4005], dp[4005][4005];

int main() {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        red[i+1] = red[i] + 2 - (s[i] - '0');
        blue[i+1] = blue[i] + (s[i] - '0');
    }

    dp[0][0] = 1;
    for (int i = 1; i <= 2 * len; i++) {
        dp[i][0] = dp[i-1][0] * (blue[min(len, i)] >= i);
        for (int j = 1; j <= i; j++) {
            // 合計i個並べたときに、赤をj個を使っている場合の数
            dp[i][j] = (dp[i-1][j] * (blue[min(len, i)] >= i-j) + dp[i-1][j-1] * (red[min(len, i)] >= j)) % mod;
        }
    }

    cout << dp[2*len][red[len]] << "\n";
    return 0;
}