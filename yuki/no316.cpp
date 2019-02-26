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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << n/a + n/b + n/c - n/lcm(a, b) - n/lcm(b, c) - n/lcm(c, a) + n/lcm(a, lcm(b, c)) << "\n";
    return 0;
}