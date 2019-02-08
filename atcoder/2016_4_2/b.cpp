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

ll R, B, x, y;

bool check(ll k) {
    if (R < k || B < k) return false;

    ll red = (R - k) / x;
    ll blue = (B - k) / y;
    if (red + blue >= k) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> R >> B >> x >> y;
    x--; y--;
    ll l = 0LL, r = 1000000000000000000LL;
    while (r - l > 1LL) {
        ll k = (r + l) / 2LL;
        check(k) ? l = k : r = k;
    }

    if (check(r)) {
        cout << r << "\n";
    } else {
        cout << l << "\n";
    }

    return 0;
}