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

    ll n, k;
    cin >> n >> k;

    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll tmp = 0;
    int r = 0;

    for (int l = 0; l < n; l++) {
        while (tmp < k && r < n) {
            tmp += a[r];
            r++;
        }

        if (tmp >= k) ans += n - r + 1;
        tmp -= a[l];
    }

    cout << ans << "\n";
    return 0;
}