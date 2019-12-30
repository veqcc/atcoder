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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, k;
    cin >> a >> b >> k;

    if (a > k) {
        cout << a - k << ' ' << b << '\n';
    } else {
        cout << 0 << ' ' << max(0LL, b - (k - a)) << '\n';
    }

    return 0;
}