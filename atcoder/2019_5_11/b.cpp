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

    ll r, g, b, n;
    cin >> r >> g >> b >> n;

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            ll cur = n - r * i - g * j;
            if (cur >= 0) {
                if (cur % b == 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}