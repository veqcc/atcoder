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

    bool same = true;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && a[i] != a[i-1]) same = false;
    }

    if (same) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 1;
    int now = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            continue;
        } else if (a[i] > a[i-1]) {
            if (now == 1) {
                continue;
            } else {
                ans++;
                now = 1;
            }
        } else {
           if (now == 2) {
               continue;
            } else {
               ans++;
               now = 2;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}