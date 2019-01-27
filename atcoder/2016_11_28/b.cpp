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

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    double a = hypot(ax - bx, ay - by);
    double b = hypot(bx - cx, by - cy);
    double c = hypot(cx - ax, cy - ay);

    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    double r = S / p;
    double mx = max({a, b, c});
    cout << fixed << setprecision(12) << mx * r / (2 * r + mx) << "\n";
    return 0;
}