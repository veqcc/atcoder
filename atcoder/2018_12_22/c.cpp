#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, p, ans=1LL;
    cin >> n >> p;
    ll d = 2LL;
    if (n >= 40LL) {
        cout << 1 << endl;
        return 0;
    } else if (n == 1LL) {
        cout << p << endl;
        return 0;
    }

    while (p > 1) {
        ll count = 0LL;
        while(p % d == 0) {
            count += 1LL;
            p /= d;
        }
        if (count >= n) {
            for (ll i = 0; i < count/n; i++) {
                ans *= d;
            }
        }
        d += 1LL;
        if (d > 1000000LL) {
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}