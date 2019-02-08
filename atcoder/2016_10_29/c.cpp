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

const int N = 100005;

int n, m, x[N], diff[N], swp[N], a[N], ret[N];
ll k, ans;

void swap_swap(int *a, int *b) {
    for (int i = 0; i < n-1; i++) ret[i] = a[b[i]];
    for (int i = 0; i < n-1; i++) a[i] = ret[i];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n-1; i++) {
        diff[i] = x[i+1] - x[i];
        swp[i] = i;
    }

    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        swap(swp[a[i]-2], swp[a[i]-1]);
    }

    while (k > 0) {
        if (k & 1) swap_swap(diff, swp);
        swap_swap(swp, swp);
        k >>= 1;
    }

    ans = x[0];
    cout << ans << "\n";
    for (int i = 0; i < n-1; i++) {
        ans += diff[i];
        cout << ans << "\n";
    }

    return 0;
}