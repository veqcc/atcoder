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

    vector <int> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    vector <int> init(n);
    for (int i = 0; i < n; i++) init[i] = i + 1;

    int ans = 0;
    bool f = false;

    do {
        bool is_p = true;
        for (int i = 0; i < n; i++) {
            if (p[i] != init[i]) {
                is_p = false;
                break;
            }
        }

        if (is_p) f ^= 1;

        bool is_q = true;
        for (int i = 0; i < n; i++) {
            if (q[i] != init[i]) {
                is_q = false;
                break;
            }
        }

        if (is_q) {
            f ^= 1;
        }

        if (f) ans++;

    } while (next_permutation(init.begin(), init.end()));

    cout << ans << "\n";
    return 0;
}