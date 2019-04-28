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

ll dp[100005][2];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <ll> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[1][0] = a[0];
    dp[1][1] = -a[0];
    for (int i = 1; i < n-1; i++) {
        dp[i+1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
        dp[i+1][1] = max(dp[i][1] + a[i], dp[i][0] - a[i]);
    }

    cout << max(dp[n-1][0] + a[n-1], dp[n-1][1] - a[n-1]) << "\n";
    return 0;
}