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
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double D = (a - c) * (a - c) - 8 * (b - d);
    if (D < 0) {
        cout << "No" << endl;
    } else if (D == 0) {
        cout << "Yes" << endl;
    } else {
        D /= 4.0;
        double x1 = ((c - a) / 2.0 + sqrt(D)) / 2.0;
        double x2 = ((c - a) / 2.0 - sqrt(D)) / 2.0;
        double y1 = x1 * x1 + a * x1 + b;
        double y2 = x2 * x2 + a * x2 + b;
        double p = (y2 - y1) / (x2 - x1);
        double q = y1 - p * x1;
        cout << fixed << setprecision(8) << p << ' ' << q << endl;
    }

    return 0;}