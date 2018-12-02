#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=1000;
const int INF=1000000007;

int n;
int a[MAX_N];
int dp[MAX_N];

// LIS : Longest Increasing Subsequence

// O(n^2)
int solve1() {
    fill(dp, dp+n, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// O(nlogn)
int solve2() {
    fill(dp, dp+n, INF);

    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }

    return lower_bound(dp, dp+n, INF) - dp;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans;
    // ans = solve1();
    ans = solve2();

    cout << ans << "\n";
    return 0;
}