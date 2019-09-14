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

    int n, m, k;
    ll e;
    cin >> n >> m >> k >> e;

    ll sum = 0;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector <ll> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());

    for (int i = 0; i < k; i++) e += b[i];

    if (e >= sum) {
        cout << "Yes\n";
        while (1) {
            e -= b[k - 1];
            if (e < sum) break;
            k--;
        }
        cout << k << '\n';
    } else {
        cout << "No\n";
        int ans = n;
        while (e < sum) {
            if (ans == 0) break;
            sum -= a[--ans];
        }
        cout << ans << '\n';
    }

    return 0;
}