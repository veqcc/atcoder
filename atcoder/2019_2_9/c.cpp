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
    cout.tie(0);

    ll k, a, b;
    cin >> k >> a >> b;

    ll ans = 0LL;
    if (1 + k <= a || b-a < 2) {
        ans = 1 + k;
    } else {
        k -= a - 1;
        ans = a + (k / 2) * (b - a);

        if (k % 2 == 1) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}