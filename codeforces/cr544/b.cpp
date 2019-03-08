#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        mp[d%k]++;
    }

    int ans = mp[0] / 2 * 2;

    if (k % 2 == 0) {
        for (int i = 1; i < k / 2; i++) {
            ans += min(mp[i], mp[k-i]) * 2;
        }
        ans += mp[k/2] / 2 * 2;
    } else {
        for (int i = 1; i <= k / 2; i++) {
            ans += min(mp[i], mp[k-i]) * 2;
        }
    }

    cout << ans << "\n";
    return 0;
}