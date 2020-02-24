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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n, x, y;
        cin >> n >> x >> y;

        ll tmp3 = min(max(0LL, n - x - 1), y - 1);
        ll tmp4 = min(max(0LL, n - y - 1), x - 1);
        ll mx = n - tmp3 - tmp4 - min(n - x - tmp3, n - y - tmp4);

        ll tmp1 = min(n - x, y - 1);
        ll tmp2 = min(n - y, x - 1);
        ll mn = min(y - 1 - tmp1, x - 1 - tmp2) + tmp1 + tmp2 + 1;

        cout << mx << ' ' << mn << '\n';
    }

    return 0;
}