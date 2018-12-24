#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    ll a[n+1];
    fill(a, a+n+1, 0);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    vector <ll> sa;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            sa.push_back(a[j] - a[i]);
        }
    }

    ll ans = 0;
    for (int i = 39; i >= 0; i--) {
        vector <ll> tmp;
        for (int j = 0; j < sa.size(); j++) {
            if (sa.at(j) & (1LL<<i)) {
                tmp.push_back(sa.at(j));
            }
            sa.at(j) %= (1LL<<i);
        }

        if (tmp.size() >= k) {
            sa = tmp;
            ans += (1LL<<i);
        }
    }

    cout << ans << endl;
    return 0;
}