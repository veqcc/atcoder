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

    int n, k;
    cin >> n >> k;

    vector <double> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    double cur = 0;
    for (int i = 0; i < k; i++) {
        cur += (p[i] + 1) / 2.0;
    }

    double ans = cur;
    for (int i = k; i < n; i++) {
        cur = cur + (p[i] + 1) / 2.0 - (p[i - k] + 1) / 2.0;
        ans = max(ans, cur);
    }

    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}