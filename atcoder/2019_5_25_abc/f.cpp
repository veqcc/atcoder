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

    multiset<ll, greater<ll>> stl;
    multiset<ll> str;
    ll ans = 0;

    while (q--) {
        ll a, b, c;
        cin >> c;

        if (c == 1) {
            cin >> a >> b;
            ans += b;

            if (stl.size() == 0) {
                stl.insert(a);
                continue;
            }

            ll lmx = *stl.begin();
            if (a < lmx) stl.insert(a);
            else str.insert(a);
            ans += abs(lmx - a);

            auto lsz = stl.size(), rsz = str.size();
            if (lsz == rsz + 2) {
                str.insert(lmx);
                stl.erase(stl.begin());
            } else if (lsz + 1 == rsz) {
                stl.insert(*str.begin());
                str.erase(str.begin());
                ans -= *stl.begin() - lmx;
            }
        } else {
            cout << *stl.begin() << ' ' << ans << '\n';
        }
    }

    return 0;
}