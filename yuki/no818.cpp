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
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector <ll> opt(n+1, 0);
    vector <ll> mx(n+1, 0);
    for (int i = 0; i < n; i++) {
        opt[i+1] = max(a[i], b[i]) + opt[i];
        mx[i+1] = max(mx[i], opt[i+1]);
    }

    vector <ll> sm(n+1, 0);
    for (int i = 0; i < n; i++) {
        ll val = max({b[i], (m-1)*a[i] + b[i], m*a[i]});
        sm[i+1] = sm[i] + val;
    }

    ll ans = - (1LL << 60);
    for (int k = 1; k <= n; k++) {
        ans = max(ans, sm[k] + (mx[n] - mx[k]));
    }

    cout << ans << "\n";
    return 0;
}