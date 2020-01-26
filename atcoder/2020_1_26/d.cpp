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

    ll h;
    cin >> h;

    ll ans = 0;
    ll tmp = 1;
    while (h) {
        ans += tmp;
        tmp *= 2;
        h /= 2;
    }

    cout << ans << "\n";
    return 0;
}