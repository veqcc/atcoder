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

    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    ll c1 = b1 - a1;
    ll c2 = b2 - a2;

    ll diff = t1 * c1 + t2 * c2;

    if (diff == 0) {
        cout << "infinity\n";
    } else if (diff > 0) {
        if (c1 > 0) {
            cout << 0 << '\n';
        } else {
            if (t1 * (-c1) % diff == 0) {
                cout << t1 * (-c1) / diff * 2 << '\n';
            } else {
                cout << t1 * (-c1) / diff * 2 + 1 << '\n';
            }
        }
    } else {
        if (c1 < 0) {
            cout << 0 << '\n';
        } else {
            if (t1 * c1 % (-diff) == 0) {
                cout << t1 * c1 / (-diff) * 2 << '\n';
            } else {
                cout << t1 * c1 / (-diff) * 2 + 1 << '\n';
            }
        }
    }

    return 0;
}