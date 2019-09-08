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

    int n, b;
    cin >> n;

    int ans = 0;
    int cur = 1 << 30;
    for (int i = 1; i < n; i++) {
        cin >> b;
        ans += min(b, cur);
        cur = b;
    }

    cout << ans + b << "\n";
    return 0;
}