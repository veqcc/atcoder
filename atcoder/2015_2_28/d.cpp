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

    int mx = 0, mx_idx = 1, dist;
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> dist;
        if (mx < dist) {
            mx = dist;
            mx_idx = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == mx_idx) continue;
        cout << "? " << mx_idx << " " << i << endl;
        cin >> dist;
        mx = max(mx, dist);
    }

    cout << "! " << mx << "\n";
    return 0;
}