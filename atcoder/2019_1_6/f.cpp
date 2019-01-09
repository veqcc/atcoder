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
    string dp[sl+1][tl+1];
    fill(dp[0], dp[sl]+tl+1, "");

    for (int i = 1; i <= sl; i++) {
        for (int j = 1; j <= tl; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + s[i-1];
            } else {
                if (dp[i-1][j].length() > dp[i][j-1].length()) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    cout << dp[sl][tl] << "\n";
    return 0;
}