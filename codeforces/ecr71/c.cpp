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
    int t;
    cin >> t;

    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        ll ans = n * a + (n + 1) * b;

        int index = 0;
        while (s[index] == '0') index++;

        if (index == n) {
            cout << ans << "\n";
            continue;
        }

        ans += a;
        while (true) {
            ans += b;
            while (s[index] == '1') {
                ans += b;
                index++;
            }
            ll count = -1;
            while (index < n && s[index] == '0') {
                count++;
                index++;
            }
            if (index == n) {
                ans += a;
                break;
            }
            ans += min(2 * a, count * b);
        }

        cout << ans << '\n';
    }

    return 0;
}