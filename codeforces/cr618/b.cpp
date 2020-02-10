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

    int n;
    cin >> n;

    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    if (n % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    bool similar = true;
    for (int i = 0; i < n / 2; i++) {
        if (x[i + 1] - x[i] != x[n/2 + i] - x[(n/2 + i + 1) % n]) similar = false;
        if (y[i + 1] - y[i] != y[n/2 + i] - y[(n/2 + i + 1) % n]) similar = false;
    }

    cout << (similar ? "YES" : "NO") << '\n';
    return 0;
}