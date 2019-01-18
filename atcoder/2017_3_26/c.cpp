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

    ll n;
    cin >> n;
    ll m = (ll)sqrt((double)n);

    while (m > 0) {
        if (n % m == 0) {
            break;
        }
        m--;
    }

    ll l = n / m;
    int ans = 0;
    while (l > 0) {
        l /= 10;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}