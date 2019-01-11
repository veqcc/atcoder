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

int main() {
    string s, t;
    cin >> s >> t;
    int sl = s.length(), tl = t.length();

    int dp[sl+1][tl+1];
    fill(dp[0], dp[sl+1], 0);

    for (int i = 0; i < sl; i++) {
        for (int j = 0; j < tl; j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    string ans = "";
    int i = sl, j = tl;
    while (dp[i][j] > 0) {
        if (s[i-1] == t[j-1]) {
            i--, j--;
            ans += s[i];
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";

    return 0;
}