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

    int n;
    cin >> n;

    vector <ll> m(n);
    for (int i = 0; i < n; i++) cin >> m[i];

    ll mx = 0;
    vector <ll> ret;
    for (int i = 0; i < n; i++) {
        ll mn = m[i];
        vector <ll> ans(n, mn);

        ll total = mn;
        for (int j = i - 1; j >= 0; j--) {
            mn = min(mn, m[j]);
            ans[j] = mn;
            total += mn;
        }

        mn = m[i];
        for (int j = i + 1; j < n; j++) {
            mn = min(mn, m[j]);
            ans[j] = mn;
            total += mn;
        }

        if (total > mx) {
            mx = total;
            ret = ans;
        }
    }

    for (ll x : ret) cout << x << ' ';
    cout << "\n";
    return 0;
}