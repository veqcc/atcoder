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

int solve(ll n, ll mx, vector <ll> &a) {
    if (mx > n) {
        ll sum = 0;
        vector <ll> b;
        for (ll x : a) {
            if (x == mx) break;
            b.push_back(x);
            sum += x;
        }

        if (sum < n) {
            b.push_back(mx / 2);
            b.push_back(mx / 2);
            return 1 + solve(n, mx / 2, b);
        } else {
            return solve(n, mx / 2, b);
        }
    }

    ll sum = 0;
    vector <ll> b;
    ll c = 0;
    for (ll x : a) {
        if (x == mx) {
            c++;
        } else {
            b.push_back(x);
            sum += x;
        }
    }

    while (c && n >= mx) {
        n -= mx;
    }

    if (n == 0) {
        return 0;
    }

    if (sum < n) {
        b.push_back(mx / 2);
        b.push_back(mx / 2);
        return 1 + solve(n, mx / 2, b);
    } else {
        return solve(n, mx / 2, b);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n, m;
        cin >> n >> m;

        ll sum = 0;
        ll mx = 0;
        vector <ll> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }

        sort(a.begin(), a.end());

        if (n > sum) {
            cout << -1 << '\n';
            continue;
        }

        cout << solve(n, mx, a) << '\n';
    }

    return 0;
}