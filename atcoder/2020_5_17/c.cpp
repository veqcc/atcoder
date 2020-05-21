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
double pi = 3.14159265358979;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double a, b, h, m;
    cin >> a >> b >> h >> m;
    h += m / 60.0;
    h *= 5.0;

    double theta = 2.0 * pi * abs(h - m) / 60.0;
    double ans = a * a + b * b - 2.0 * a * b * cos(theta);

    cout << fixed << setprecision(12) << sqrt(ans) << "\n";
    return 0;
}