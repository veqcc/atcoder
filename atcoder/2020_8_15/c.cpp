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
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    if (x / d >= k) {
        cout << x - d * k << endl;
    } else {
        k -= x / d;
        x %= d;
        if (k % 2 == 0) {
            cout << x << endl;
        } else {
            cout << d - x << endl;
        }
    }

    return 0;
}