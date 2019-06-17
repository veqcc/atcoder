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
const double INF = 1000000000.0;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    double u1 = -INF, u2 = -INF, u3 = -INF;
    double d1 =  INF, d2 =  INF, d3 =  INF;
    double l1 =  INF, l2 =  INF, l3 =  INF;
    double r1 = -INF, r2 = -INF, r3 = -INF;

    for (int i = 0; i < n; i++) {
        double x, y;
        char d;
        cin >> x >> y >> d;

        if (d == 'D') {
            u1 = max(u1, y);
            d3 = min(d3, y);
            l2 = min(l2, x);
            r2 = max(r2, x);
        } else if (d == 'U') {
            u3 = max(u3, y);
            d1 = min(d1, y);
            l2 = min(l2, x);
            r2 = max(r2, x);
        } else if (d == 'R') {
            u2 = max(u2, y);
            d2 = min(d2, y);
            l1 = min(l1, x);
            r3 = max(r3, x);
        } else if (d == 'L') {
            u2 = max(u2, y);
            d2 = min(d2, y);
            l3 = min(l3, x);
            r1 = max(r1, x);
        }
    }

    // ぶつかる時間のvector
    vector <double> vec;
    vec.push_back(0);

    // Up
    vec.push_back(u1 - u2);
    vec.push_back(u2 - u3);
    vec.push_back((u1 - u3) / 2);

    // Down
    vec.push_back(d2 - d1);
    vec.push_back(d3 - d2);
    vec.push_back((d3 - d1) / 2);

    // Left
    vec.push_back(l2 - l1);
    vec.push_back(l3 - l2);
    vec.push_back((l3 - l1) / 2);

    // Right
    vec.push_back(r1 - r2);
    vec.push_back(r2 - r3);
    vec.push_back((r1 - r3) / 2);

    double ans = 40000000000000000;
    for (double d : vec) {
        if (d < 0) continue;
        double u = max({u2, u1 - d, u3 + d});
        double f = min({d2, d1 + d, d3 - d});
        double l = min({l2, l1 + d, l3 - d});
        double r = max({r2, r1 - d, r3 + d});

        ans = min(ans, (u - f) * (r - l));
    }

    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}