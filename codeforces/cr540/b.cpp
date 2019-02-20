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

    int a[n];
    int od_sm = 0, ev_sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) {
            od_sm += a[i];
        } else {
            ev_sm += a[i];
        }

        if (i > 1) {
            a[i] += a[i-2];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            int odd = a[i-1] + ev_sm - a[i];
            int even = od_sm - a[i-1];
            if (i > 1) even += a[i-2];
            if (odd == even) {
                ans++;
            }
        } else {
            int odd = ev_sm;
            if (i > 0) odd -= a[i-1];
            if (i > 1) odd += a[i-2];

            int even = od_sm - a[i];
            if (i > 0) even += a[i-1];

            if (odd == even) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}