#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll a[n], b[n];
    vector <pair<ll, int>> sm;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sm.push_back(make_pair(a[i]+b[i], i));
    }

    sort(sm.begin(), sm.end());

    ll ans = 0LL;
    for (int i = n-1; i >= 0; i--) {
        if ((n-1-i) % 2 == 0) {
            ans += a[sm[i].second];
        } else {
            ans -= b[sm[i].second];
        }
    }

    cout << ans << "\n";
    return 0;
}