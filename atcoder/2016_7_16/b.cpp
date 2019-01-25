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

    ll n, x;
    cin >> n >> x;

    ll ans = n;
    ll w = x; // width
    ll h = n - x; // height

    while (true) {
        if (w > h) {
            if (w % h == 0) {
                ans += (w / h) * h * 2 - h;
                break;
            }
            ans += (w / h) * h * 2;
            w = w % h;
        } else {
            if (h % w == 0) {
                ans += (h / w) * w * 2 - w;
                break;
            }
            ans += (h / w) * w * 2;
            h = h % w;
        }
    }

    cout << ans << "\n";
    return 0;
}