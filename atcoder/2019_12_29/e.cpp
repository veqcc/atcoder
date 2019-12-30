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

ll check(vector <ll> &a, ll med) {
    ll ret = 0;
    ll n = a.size();
    for (int i = 0; i < n; i++) {
        ret += a.end() - lower_bound(a.begin(), a.end(), med - a[i]);
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll l = 0, r = 1LL << 40;
    while (r - l > 1) {
        ll med = (l + r) / 2;

        ll c = check(a, med);
        if (c < m) {
            r = med;
        } else {
            l = med;
        }
    }

    ll diff = check(a, l) - m;

    vector <ll> sm(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        sm[i] = sm[i + 1] + a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll idx = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
        ans += sm[idx];
        ans += (n - idx) * a[i];
    }

    cout << ans - diff * l << "\n";
    return 0;
}