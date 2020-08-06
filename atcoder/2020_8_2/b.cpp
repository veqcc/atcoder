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
    ll n, d;
    cin >> n >> d;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ans += x * x + y * y <= d * d;
    }

    cout << ans << endl;
    return 0;
}