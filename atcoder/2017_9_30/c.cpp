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

    ll N;
    cin >> N;

    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 2; n <= 3500; n++) {
            ll numerator = N * h * n;
            ll dominator = 4 * h * n - N * n - N * h;
            if (dominator > 0 && numerator % dominator == 0) {
                cout << h << ' ' << n << ' ' << numerator / dominator << '\n';
                return 0;
            }
        }
    }

    return 0;
}