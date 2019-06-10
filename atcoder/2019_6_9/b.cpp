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

    int n;
    cin >> n;

    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        if (i) w[i] += w[i-1];
    }

    int ans = 1 << 30;
    for (int i = 0; i < n-1; i++) {
        int diff = abs(w[i] - w[n-1] + w[i]);
        ans = min(ans, diff);
    }

    cout << ans << "\n";
    return 0;
}