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
    ll n, k;
    cin >> n >> k;

    vector<ll> p(n), c(n);
    for (int i = 0; i < n; i++) { cin >> p[i]; p[i]--; }
    for (int i = 0; i < n; i++) cin >> c[i];

    ll ans = -1e9;
    for (int i = 0; i < n; i++) {
        ll sum = 0, cur = i, num = 0;
        do {
            cur = p[cur];
            sum += c[cur];
            num++;
        } while (cur != i);

        ll tmp = 0, mx = -1e9;
        for (int j = 1; j <= min(k, num); j++) {
            cur = p[cur];
            tmp += c[cur];
            mx = max(mx, tmp + (sum > 0 ? sum * ((k - j) / num) : 0));
        }

        ans = max(ans, mx);
    }

    cout << ans << endl;
    return 0;
}