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

    ll l, r, n;
    cin >> l >> r >> n;

    for (ll i = 0; i < n; i++) {
        ll p = l + i - (l % n);
        if (p < l) p += n;

        if (r < p) {
            cout << 0 << '\n';
        } else {
            cout << 1LL + (r - p) / n << '\n';
        }
    }

    return 0;
}