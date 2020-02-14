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

    while (T--) {
        int n;
        cin >> n;

        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mx = 0, mn = 1e9;
        int max_diff = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == -1 && a[i + 1] != -1) {
                mx = max(mx, a[i + 1]);
                mn = min(mn, a[i + 1]);
            } else if (a[i] != -1 && a[i + 1] == -1) {
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            } else if (a[i] != -1 && a[i + 1] != -1) {
                max_diff = max(max_diff, abs(a[i] - a[i + 1]));
            }
        }

        int k = (mx + mn) / 2;
        max_diff = max(max_diff, mx - k);
        cout << max_diff << ' ' << k << '\n';
    }

    return 0;
}