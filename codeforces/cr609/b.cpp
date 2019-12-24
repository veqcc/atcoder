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

    ll n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll white = 0, black = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            white += a[i] / 2;
            black += a[i] - a[i] / 2;
        } else {
            white += a[i] - a[i] / 2;
            black += a[i] / 2;
        }
    }

    cout << min(white, black) << "\n";
    return 0;
}