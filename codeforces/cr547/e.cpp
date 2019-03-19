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

    ll H, n;
    cin >> H >> n;

    ll sm[n], mx = 0;
    for (int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        h = -h;
        sm[i] = h;
        if (i) sm[i] += sm[i-1];
        mx = max(mx, sm[i]);
    }

    for (int i = 0; i < n; i++) {
        if (H <= sm[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    if (sm[n-1] <= 0) {
        cout << -1 << '\n';
        return 0;
    }

    ll ans = (H - mx) / sm[n-1];
    if ((H - mx) % sm[n-1] > 0) ans++;

    H -= ans * sm[n-1];
    ans *= n;

    for (int i = 0; i < n; i++) {
        if (H <= sm[i]) {
            ans += i + 1;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}