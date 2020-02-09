#include <functional>
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

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector <int> dp(300005);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            dp[1] = 1;
            continue;
        }

        auto div = divisor(a[i]);
        for (int val : div) {
            if (val == a[i]) continue;
            dp[a[i]] = max(dp[a[i]], dp[val] + 1);
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[a[i]]);
    }

    cout << ans << "\n";
    return 0;
}