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

    int n, k;
    cin >> n >> k;
    ll h[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    sort(h, h+n);

    ll ans = h[k-1] - h[0];

    for (int i = 0; i <= n - k; i++) {
        ans = min(ans, h[i+k-1] - h[i]);
    }

    cout << ans << "\n";
    return 0;
}