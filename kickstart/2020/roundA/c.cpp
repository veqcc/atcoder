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

    for (int t = 1; t <= T; t++) {
        int n, k;
        cin >> n >> k;

        vector <int> m(n);
        for (int i = 0; i < n; i++) cin >> m[i];

        int l = 0, r = 1e9;
        while (r - l > 1) {
            int mid = (r + l) / 2;

            int need = 0;
            for (int i = 0; i < n - 1; i++) {
                int diff = m[i + 1] - m[i];
                need += (diff - 1) / mid;
            }

            if (need <= k) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << "Case #" << t << ": " << r << '\n';
    }

    return 0;
}