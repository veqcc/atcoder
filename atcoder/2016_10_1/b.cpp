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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n, a, place[200005], ans=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        place[a] = i;
    }

    set<ll> s;
    s.insert(0);
    s.insert(n+1);

    for (ll i = 1; i <= n; i++) {
        auto x = s.upper_bound(place[i]);
        auto y = x--;
        ans += i * (*x - place[i]) * (place[i] - *y);
        s.insert(place[i]);
    }

    cout << ans << "\n";
    return 0;
}