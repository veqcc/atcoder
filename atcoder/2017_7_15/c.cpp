#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n];
    fill(a, a+n, 0LL);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0) a[i] += a[i-1];
    }

    ll ans = 1e+15;
    for (int i = 0; i < n-1; i++) {
        ans = min(ans, abs(a[n-1] - 2*a[i]));
    }

    cout << ans << endl;
    return 0;
}