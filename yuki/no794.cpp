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

const ll MOD = 1000000007LL;

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector <ll> a(n);
    ll mx = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (mx >= k) {
        cout << 0 << "\n";
        return 0;
    }

    sort(a.begin(), a.end());

    if (a[n/2-1] * 2 > k) {
        cout << 0 << "\n";
        return 0;
    }

    ll ans = 1LL;
    int i;
    for (i = 0; i < n/2; i++) {
        if (a[n-i-1] * 2 <= k) break;
        int idx = lower_bound(a.begin(), a.end(), k - a[n-i-1]+1) - a.begin();
        ans = ans * (ll)(idx - i) % MOD;
    }

    int remain = n - i * 2;
    while (remain) {
        ans = ans * (remain - 1) % MOD;
        remain -= 2;
    }

    cout << ans << "\n";
    return 0;
}