#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int x[m];
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    sort(x, x+m);

    int diff[m-1];
    for (int i = 0; i < m-1; i++) {
        diff[i] = x[i+1] - x[i];
    }

    sort(diff, diff+m-1);

    if (n >= m) {
        cout << 0 << "\n";
    } else {
        ll ans = 0LL;
        for (int i = 0; i < m - n; i++) {
            ans += (ll)diff[i];
        }
        cout << ans << "\n";
    }

    return 0;
}