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

    int n, d, e;
    cin >> n >> d >> e;

    e *= 5;
    int mx = max(d, e);
    int mn = min(d, e);

    int ans = n;
    for (int i = 0; i <= n; i += mx) {
        ans = min(ans, (n - i) % mn);
    }

    cout << ans << "\n";
    return 0;
}