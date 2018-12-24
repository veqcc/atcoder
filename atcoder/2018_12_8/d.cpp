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

    ll n, x;
    cin >> n >> x;

    ll sm[n+1], p[n+1];
    sm[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        sm[i] = sm[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }

    ll ans = 0;
    for (int i = n; i >= 0; i--) {
        if (x <= sm[i]/2) {
            x -= 1;
        } else if (x == sm[i]/2 + 1) {
            ans += p[i]/2 + 1;
            break;
        } else if (x <= sm[i]-1) {
            ans += p[i]/2 + 1;
            x -= (sm[i]/2 + 1);
        } else {
            ans += p[i];
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}