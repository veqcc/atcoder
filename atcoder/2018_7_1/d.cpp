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

int main() {
    int n;
    cin >> n;

    vector <ll> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    ll ans = 1LL << 60;
    for (int i = 2; i < n-1; i++) {
        ll p = a[i] / 2;
        int p_idx = lower_bound(a.begin(), a.end(), p) - a.begin();
        ll p_max = max(a[p_idx], a[i] - a[p_idx]);
        ll p_min = min(a[p_idx], a[i] - a[p_idx]);
        ll tmp_max = max(a[p_idx - 1], a[i] - a[p_idx - 1]);
        ll tmp_min = min(a[p_idx - 1], a[i] - a[p_idx - 1]);
        if (p_max - p_min > tmp_max - tmp_min) {
            p_max = tmp_max;
            p_min = tmp_min;
        }

        ll r = (a[n] - a[i]) / 2 + a[i];
        int r_idx = lower_bound(a.begin(), a.end(), r) - a.begin();
        ll r_max = max(a[r_idx] - a[i], a[n] - a[r_idx]);
        ll r_min = min(a[r_idx] - a[i], a[n] - a[r_idx]);
        tmp_max = max(a[r_idx - 1] - a[i], a[n] - a[r_idx - 1]);
        tmp_min = min(a[r_idx - 1] - a[i], a[n] - a[r_idx - 1]);
        if (r_max - r_min > tmp_max - tmp_min) {
            r_max = tmp_max;
            r_min = tmp_min;
        }

        ans = min(ans, max(p_max, r_max) - min(p_min, r_min));
    }

    cout << ans << "\n";
    return 0;
}