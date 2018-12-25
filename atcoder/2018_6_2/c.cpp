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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll N, D;
    cin >> N >> D;
    ll x[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    ll ans = 0LL;
    for (ll i = 1; i < N-1; i++) {
        ll pre = lower_bound(x, x+N, x[i]-D) - x;
        ll pos = upper_bound(x, x+N, x[i]+D) - x;
        ans += (i - pre) * (pos - i - 1LL);
    }

    for (ll i = 0; i < N-2; i++) {
        ll len = upper_bound(x, x+N, x[i]+D) - x;
        ans -= (len - i - 1LL) * (len - i - 2LL) / 2LL;
    }

    cout << ans << "\n";
    return 0;
}