#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int x, y;
// ax + by = gcd(a, b) の解を与える。
int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
    cout << gcd(12, 18) << "\n"; // 6

    extgcd(4, 11, x, y);
    cout << x << " " << y << "\n"; // 4*3 + 11*(-1) = gcd(4, 11) = 1
    return 0;
}