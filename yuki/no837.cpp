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

    int n;
    cin >> n;

    ll y[n];
    for (int i = 0; i < n; i++) cin >> y[i];

    sort(y, y+n);

    if (y[0] == y[n-1]) {
        cout << 1 << "\n";
        return 0;
    }

    int idx1 = 0;
    ll l = 0;
    bool pre_odd = true;

    int idx2 = (n + 1) / 2;
    ll r = 0;
    bool pos_odd = n % 2 == 0;

    for (int i = 1; i < n; i++) {
        if (i < idx2) {
            r -= y[i];
        } else if (i > idx2 || !pos_odd) {
            r += y[i];
        }
    }

    ll ans = l + r;

    for (int i = 1; i < n - 1; i++) {
        // iを後ろから前に移動する
        l += y[i];
        l -= y[idx1];
        if (pre_odd) {
            idx1++;
            pre_odd = false;
        } else {
            pre_odd = true;
        }

        r += y[i];
        r -= y[idx2];
        if (pos_odd) {
            idx2++;
            pos_odd = false;
        } else {
            pos_odd = true;
        }

        ans = min(ans, l + r);
    }

    cout << ans << "\n";
    return 0;
}