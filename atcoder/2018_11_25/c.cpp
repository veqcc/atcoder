#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

ll a = 100000000;
int main() {
    int n;
    cin >> n;
    ll x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] += a;
    }

    sort(x, x+n);

    ll ans[n];
    fill(ans, ans+n, 0);
    ans[0] = 0;
    ans[1] = x[1] - x[0];
    for (int i = 2; i < n; i++) {
        ans[i] = (x[i]-x[i-1]) * (ll)i + 2 * ans[i-1] - ans[i-2];
    }

    cout << ans[n-1] << endl;
    return 0;
}