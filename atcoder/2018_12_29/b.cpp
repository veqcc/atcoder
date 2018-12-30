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

ll l, n, x[200005];

ll rec(ll lhs, ll rhs, bool turn_right) {
    if (lhs == -1) {
        if (turn_right) {
            return l - x[rhs];
        } else {
            return x[rhs];
        }
    } else if (rhs == n) {
        if (turn_right) {
            return l - x[lhs];
        } else {
            return x[lhs];
        }
    }

    if (turn_right) {
        return (l - x[rhs] + x[lhs]) + rec(lhs, rhs + 1, false);
    } else {
        return (l - x[rhs] + x[lhs]) + rec(lhs - 1, rhs, true);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    if (n == 1) {
        cout << max(x[0], l - x[0]);
        return 0;
    }

    ll ans = 0LL;
    for (ll i = 0; i < n - 1; i++) {
        ans = max(ans, rec(i, i + 1, true));
        ans = max(ans, rec(i, i + 1, false));
    }

    cout << ans << "\n";
    return 0;
}
