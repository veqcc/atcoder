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
const ll inf = 1LL << 40;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, s;
    cin >> n >> s;

    ll sqr = (ll) sqrt((double) n);
    ll ret = inf;

    if (s == n) {
        ret = n + 1LL;
    } else if (s < n) {
        // bが√n以下を探す
        for (ll i = 2LL; i <= sqr; i++) {
            ll t = n, ans = 0LL;
            while (t > 0) {
                ans += t % i;
                t /= i;
            }
            if (ans == s) {
                ret = min(ret, i);
            }
        }

        // bが√n以上を探す
        for (ll p = 1LL; p <= sqr && p <= s; p++) {
            ll q = s - p; // p + q = s
            if ((n - s) % p == 0) {
                ll b = (n - s) / p + 1LL; // n = bp + q
                if (b > p && b > q) {
                    ret = min(ret, b);
                }
            }
        }
    }

    if (ret == inf) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }

    return 0;
}