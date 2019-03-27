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

int dp[305][305];
// [i, j)の取り除ける文字数

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    for (int len = 3; len <= n; len++) {
        for (int left = 0; left + len <= n; left++) {
            for (int mid = left + 1; mid < left + len; mid++) {
                dp[left][left + len] = max(dp[left][left + len], dp[left][mid] + dp[mid][left + len]);
            }

            if (s[left] == 'i' && s[left + len - 1] == 'i') {
                for (int w = left; w < left + len; w++) {
                    if (s[w] == 'w') {
                        if (dp[left + 1][w] == w - left - 1 && dp[w + 1][left + len - 1] == left + len - w - 2) {
                            dp[left][left + len] = len;
                        }
                    }
                }
            }
        }
    }

    cout << dp[0][n] / 3 << "\n";
    return 0;
}