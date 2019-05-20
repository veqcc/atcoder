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

    int m, k;
    cin >> m >> k;

    int n = pow(2, m);

    if (pow(2, m) <= k) {
        cout << -1 << "\n";
        return 0;
    }

    if (m == 1) {
        if (k == 1) {
            cout << -1 << "\n";
            return 0;
        } else {
            cout << "0 0 1 1\n";
            return 0;
        }
    }

    cout << k << " ";
    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        cout << i << " ";
    }
    cout << k << " ";
    for (int i = n-1; i >= 0; i--) {
        if (i == k) continue;
        cout << i << " ";
    }

    return 0;
}