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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    vector <int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    int mx = 0;
    for (int i = 1; i <= m; i++) {
        vector <bool> used(k + 1, false);
        int ans = 0;
        for (int j : x) {
            int diff = abs(i - j);
            if (diff == 0) {
                ans++;
            } else if (diff <= k && !used[diff]) {
                used[diff] = true;
                ans++;
            }
        }
        mx = max(mx, ans);
    }

    cout << mx << "\n";
    return 0;
}
