#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int ans = n;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1] * 2) {
            ans = n - i;
        }
        a[i] += a[i-1];
    }

    cout << ans << "\n";
    return 0;
}