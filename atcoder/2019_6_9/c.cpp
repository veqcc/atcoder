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

ll dp[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <bool> broken(n+1, false);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (broken[i]) continue;

        if (i == 1) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}