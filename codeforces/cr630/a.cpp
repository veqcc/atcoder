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

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int X = x + b - a;
        int Y = y + d - c;

        bool ok = true;

        if (X < x1) ok = false;
        if (X > x2) ok = false;
        if (Y < y1) ok = false;
        if (Y > y2) ok = false;
        if (abs(a) + abs(b) > 0 && x1 == x2) ok = false;
        if (abs(c) + abs(d) > 0 && y1 == y2) ok = false;

        if (ok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}