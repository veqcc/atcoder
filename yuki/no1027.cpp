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

    int d1, d2;
    cin >> d1 >> d2;

    int ans;
    if (2 * d1 < d2 || d1 > d2) {
        ans = 0;
    } else if (2 * d1 == d2 || d1 == d2) {
        ans = 4;
    } else {
        ans = 8;
    }

    cout << ans << "\n";
    return 0;
}