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

ll f(ll x) {
    if (x == 3LL) {
        return 6LL;
    } else {
        return x * (x - 1) + f(x - 1);
    }
}

int main() {
    ll n;
    cin >> n;

    cout << f(n) << "\n";
    return 0;
}