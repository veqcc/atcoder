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

    int n;
    cin >> n;

    int a[n], b[n];
    int ans = 0;
    int tmp = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        int mn = min(a[i], b[i]);
        int mx = max(a[i], b[i]);

        if (tmp <= mn) {
            ans += max(mx - mn - 1, 0);
        } else {
            ans += max(mx - tmp - 1, 0);
        }
        tmp = mx - 1;
    }

    if (a[n-1] == b[n-1]) {
        cout << a[n-1] + 1 - ans << "\n";
    } else {
        cout << max(a[n-1], b[n-1]) - ans << "\n";
    }
    return 0;
}