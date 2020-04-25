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

    int q;
    cin >> q;

    while (q--) {
        ll n, i, j;
        cin >> n >> i >> j;

        ll mn = min(min(i, n - i - 1), min(j, n - j - 1));

        ll ans = 0;
        ans += 4 * (n - mn) * mn;

        if (i == mn) {
            cout << ans + (j - mn) << endl;
        } else if (j == n - mn - 1) {
            cout << ans + (n - 2 * mn - 1) + (i - mn) << endl;
        } else if (i == n - mn - 1) {
            cout << ans + 2 * (n - 2 * mn - 1) + (n - mn - 1 - j) << endl;
        } else {
            cout << ans + 3 * (n - 2 * mn - 1) + (n - mn - 1 - i) << endl;
        }
    }

    return 0;
}