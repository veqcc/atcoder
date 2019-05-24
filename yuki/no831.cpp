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

    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    ll ans = 0;
    if (n % 2 == 0) {
        ll m = n;
        for (int i = 0; i < n / 2; i++) {
            ans += m * (2 * i + 2);
            m--;
        }

        ans += n;
        ans -= (n / 2) + 1;
    } else {
        ll m = n;
        for (int i = 0; i < n / 2; i++) {
            ans += m * (2 * i + 2);
            m--;
        }

        ans += n;
        ans += (n / 2) * (n / 2 + 1);
    }

    cout << ans << "\n";
    return 0;
}