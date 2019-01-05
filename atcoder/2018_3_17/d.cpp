#include <algorithm>
#include <iostream>
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

    int n, t;
    cin >> n;

    vector <int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        b.push_back(t);
    }

    int ans = 0;
    for (int k = 29; k >= 0; k--) {
        for (int i = 0; i < n; i++) {
            a[i] %= 1 << (k + 1);
            b[i] %= 1 << (k + 1);
        }

        sort(b.begin(), b.end());

        ll count = 0;
        for (int i = 0; i < n; i++) {
            count += lower_bound(b.begin(), b.end(), 2*(1<<k)-a[i]) - lower_bound(b.begin(), b.end(), (1<<k)-a[i]);
            count += lower_bound(b.begin(), b.end(), 4*(1<<k)-a[i]) - lower_bound(b.begin(), b.end(), 3*(1<<k)-a[i]);
        }

        if (count % 2LL == 1LL) {
            ans += (1 << k);
        }
    }

    cout << ans << "\n";
    return 0;
}