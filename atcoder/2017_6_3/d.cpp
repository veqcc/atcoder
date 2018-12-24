#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
ll n, a, b, h[1000005];

ll binary_search(ll s, ll g) {
    ll k = (g + s) / 2;
    ll t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > b * k) {
            t1 += (h[i] - b * k + a - 1) / a;
        }
        if (h[i] > b * (k - 1)) {
            t2 += (h[i] - b * (k - 1) + a - 1) / a;
        }
    }

    ll ret;
    if (t1 > k) { // kで倒せない
        ret = binary_search(k, g);
    } else { // kで倒せる
        if (t2 > k-1) { // k-1で倒せない
            ret = k;
        } else {
            ret = ret = binary_search(s, k);
        }
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    a -= b;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    cout << binary_search(0, 1000000000) << "\n";
    return 0;
}