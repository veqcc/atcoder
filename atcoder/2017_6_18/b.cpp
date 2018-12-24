#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    int mx = a[0];
    int mn = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    bool ans = true;

    if (mx - mn >= 2) {
        ans = false;
    } else if (mx - mn == 1) {
        int mxc=0, mnc=0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx) mxc++;
            if (a[i] == mn) mnc++;
        }

        if (mxc == 1) ans = false;
        if (mnc >= mx) ans = false;
        if (mx - mnc > mxc/2) ans = false;
    } else {
        if (mx == n - 1) {
            ans = true;
        } else if (mx * 2 <= n) {
            ans = true;
        } else {
            ans = false;
        }
    }

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}