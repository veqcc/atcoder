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
typedef unsigned int uint;
using namespace std;
typedef pair<ll, ll> P;
const ll INF = 1LL << 50;
ll x1, Y1, x2, y2, n, x, y;
P cur[100005];

bool check(ll times) {
    ll period = times / n;
    ll remain = times % n;
    ll x_diff = abs(x * period + cur[remain].first + x1 - x2);
    ll y_diff = abs(y * period + cur[remain].second + Y1 - y2);
    return x_diff + y_diff <= times;
}

int main() {
    string s;
    cin >> x1 >> Y1 >> x2 >> y2 >> n >> s;

    x = 0; y = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'R') x++;
        if (s[i] == 'L') x--;
        cur[i+1] = P(x, y);
    }

    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2LL;
        bool reachable = check(mid);
        reachable ? r = mid : l = mid;
    }

    if (l == INF - 1) cout << -1 << "\n";
    else cout << (check(l) ? l : r) << "\n";
    return 0;
}