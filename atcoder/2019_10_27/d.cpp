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
const double pi = 3.14159265358979;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double a, b, x;
    cin >> a >> b >> x;

    cout << fixed << setprecision(12);
    if (2 * x <= a * a * b) {
        cout << atan(a * b * b / 2 / x) * 180.0 / pi << '\n';
    } else {
        cout << atan(2 * b / a - 2 * x / a / a / a) * 180.0 / pi << '\n';
    }

    return 0;
}