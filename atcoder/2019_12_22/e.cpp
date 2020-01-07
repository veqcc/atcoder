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

    ll n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << '\n';
    } else {
        ll ans = 0;
        for (ll i = 10; i <= n; i *= 5) {
            ans += n / i;
            if (i > n / 5) break;
        }
        cout << ans << '\n';
    }

    return 0;
}