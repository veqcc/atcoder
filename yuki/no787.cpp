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
    double p, q;
    cin >> p >> q;
    p /= 100.0;
    q /= 100.0;

    cout << fixed << setprecision(12) << 100.0 * (p * q) / (p * q + (1.0 - p) * (1.0 - q)) << "\n";
    return 0;
}