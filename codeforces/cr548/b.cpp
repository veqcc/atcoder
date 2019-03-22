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

    int n;
    cin >> n;

    vector <ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    reverse(a.begin(), a.end());

    ll tmp = a[0] - 1;
    ll ans = a[0];

    for (int i= 1; i < a.size(); i++) {
        if (tmp == 0) break;

        if (a[i] >= tmp) {
            ans += tmp;
            tmp--;
        } else {
            ans += a[i];
            tmp = a[i] - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}