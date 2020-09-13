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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = -1e18;
    ans = max(ans, a * c);
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);

    cout << ans << endl;
    return 0;
}