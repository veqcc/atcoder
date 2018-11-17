#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int n, k;
ll a[100005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
        ll tmp = a[i];
        for (int j = i; j >= max(0, i-k+1); j--) {
            tmp = min(tmp, a[j]);
        }
        ans += tmp;
    }

    cout << ans << endl;
    return 0;
}