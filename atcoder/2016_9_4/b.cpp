#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    ll a[n], b[n], ret=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        ret += a[i];
    }

    for (ll k = 0; k < n; k++) { // k回魔法を唱える
        ll ans = k * x;
        for (int i = 0; i < n; i++) {
            b[i] = min(b[i], a[(i-k+n)%n]);
            ans += b[i];
        }
        ret = min(ret, ans);
    }

    cout << ret << "\n";
    return 0;
}