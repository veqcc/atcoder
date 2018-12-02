#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=1000, MAX_M=1000;

int n, m;
string s, t;
int dp[MAX_N][MAX_M];

// LCS : Longest Common Subsequence

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;

    fill(dp[0], dp[MAX_N-1]+MAX_M, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}