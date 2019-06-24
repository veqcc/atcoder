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

    int n, l;
    cin >> n >> l;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += l + i;
    }

    if (l > 0) {
        ans -= l;
    } else if (l + n - 1 < 0) {
        ans -= l + n - 1;
    }

    cout << ans << "\n";
    return 0;
}