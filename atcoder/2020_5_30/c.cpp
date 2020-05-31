#include <functional>
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
    int n;
    cin >> n;

    vector<ll> a(n + 1), sm(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        if (i) sm[i - 1] = a[i];
    }

    for (int i = n; i; i--) sm[i - 1] += sm[i];

    ll ans = 0, cur = 1;
    for (int i = 0; i <= n; i++) {
        ans += cur;

        cur -= a[i];

        if (cur < 0) {
            cout << -1 << endl;
            return 0;
        }

        cur = min(cur * 2, sm[i]);
    }

    cout << ans << endl;
    return 0;
}