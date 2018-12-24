#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll n, T;
ll t[200005];

int main() {
    cin >> n >> T >> t[0];
    ll ans = T;
    for (int i = 1; i < n; i++) {
        cin >> t[i];
        ans += min(T, t[i] - t[i-1]);
    }

    cout << ans << endl;
    return 0;
}