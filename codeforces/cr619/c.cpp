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

    int T;
    cin >> T;

    while (T--) {
        ll n, m;
        cin >> n >> m;

        ll total = n * (n - 1) / 2 + n;

        if (n < 2 * m) {
            cout << total - (n - m) << '\n';
        } else {
            ll remain = n - m;
            ll section = m + 1;

            map <ll, int> mp;
            ll tmp = remain / section;
            mp[tmp + 1] = remain % section;
            mp[tmp] = section - mp[tmp + 1];

            ll ans = total;
            ans -= mp[tmp + 1] * ((tmp + 1) * tmp / 2 + tmp + 1);
            ans -= mp[tmp] * ((tmp - 1) * tmp / 2 + tmp);

            cout << ans << '\n';
        }
    }

    return 0;
}