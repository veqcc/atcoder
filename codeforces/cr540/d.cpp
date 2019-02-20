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

int n;
ll m, a[100005];

bool check(int x) {
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        sm += max(a[i] - (i / x), 0LL);
    }

    if (sm >= m) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    if (m > sm) {
        cout << -1 << "\n";
        return 0;
    }

    sort(a, a+n, greater<ll>());

    int l = 1, r = n;
    while (r - l > 1) {
        int md = (r + l) / 2;
        if (check(md)) {
            r = md;
        } else {
            l = md;
        }
    }

    if (check(l)) {
        cout << l << "\n";
    } else {
        cout << r << "\n";
    }

    return 0;
}