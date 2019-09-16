#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;

        int ans = 0;
        if (h >= c) {
            while (b > 1 && p) {
                ans += h;
                b -= 2;
                p--;
            }

            while (b > 1 && f) {
                ans += c;
                b -= 2;
                f--;
            }
        } else {
            while (b > 1 && f) {
                ans += c;
                b -= 2;
                f--;
            }
            while (b > 1 && p) {
                ans += h;
                b -= 2;
                p--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}