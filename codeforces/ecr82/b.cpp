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

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n, g, b;
        cin >> n >> g >> b;

        if (g >= b) {
            cout << n << '\n';
        } else {
            int m = (n + 1) / 2;
            ll sum = g + b;

            if (m % g == 0) {
                cout << max(m / g * sum - b, n) << '\n';
            } else {
                cout << max(m / g * sum + m % g, n) << '\n';
            }
        }
    }

    return 0;
}