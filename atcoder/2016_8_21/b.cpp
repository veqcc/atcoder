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
    ll ans = 0;
    bool remain = false;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (remain) {
            if (a == 0) {
                remain = false;
            } else {
                a += 1;
                ans += a / 2;
                if (a % 2 == 0) {
                    remain = false;
                }
            }
        } else {
            ans += a / 2;
            if (a % 2 == 1) {
                remain = true;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}