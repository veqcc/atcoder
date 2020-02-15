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
    ll k;
    cin >> n >> m >> k;

    char op;
    cin >> op;

    vector <ll> a(n), b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector <ll> val(n);
    if (op == '+') {
        for (int i = 0; i < n; i++) {
            val[i] = k - a[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            val[i] = (k + a[i] - 1) / a[i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(b.begin(), b.end(), val[i]) - b.begin();
        ans += m - idx;
    }

    cout << ans << '\n';
    return 0;
}