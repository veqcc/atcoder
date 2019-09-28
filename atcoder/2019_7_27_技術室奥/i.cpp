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

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector <ll> mn(n);
    for (int i = 0; i < n; i++) {
        mn[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    vector <ll> sum(n, mn[0]);
    for (int i = 1; i < n; i++) {
        sum[i] = (sum[i - 1] + mn[i]) % MOD;
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ll mx = b.end() - upper_bound(b.begin(), b.end(), a[i]);
        ans += mx * sum[i - 1] % MOD;
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}