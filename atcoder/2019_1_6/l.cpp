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
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n+1][n+1];
    fill(dp[0], dp[n+1], 0);
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j <= n; j++) {
            if (n % 2 == (j - i) % 2) { // taro
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            } else { // jiro
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][n] << "\n";
    return 0;
}