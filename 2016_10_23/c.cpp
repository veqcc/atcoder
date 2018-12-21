#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const ll mod = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll t[n], a[n];
    bool possible = true;
    bool fixed[n];

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (i == 0 || t[i] > t[i - 1]) {
            fixed[i] = true;
        } else {
            fixed[i] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n-1; i >= 0; i--) {
        if (i == n-1 || a[i] > a[i+1]) {
            if (fixed[i] && t[i] != a[i]) {
                possible = false;
            }
            if (t[i] < a[i]) {
                possible = false;
            }
            fixed[i] = true;
        }
        t[i] = min(t[i], a[i]);
    }

    ll ans = 1LL;
    for (int i = 0; i < n; i++) {
        if (!(fixed[i])) {
            ans = ans * t[i] % mod;
        }
    }

    if (!(possible)) ans = 0LL;

    cout << ans << "\n";
    return 0;
}