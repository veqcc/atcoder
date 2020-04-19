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
typedef long double ld;

class Combination {
public:
    vector <ld> log_fac;
    Combination(int N) : log_fac(N + 1) {
        for (ld i = 2; i <= N; i++) {
            log_fac[i] = log_fac[i - 1] + log(i);
        }
    }
    ld C(int n, int k) {
        if (k < 0 || n < k) return 0;
        return log_fac[n] - log_fac[k] - log_fac[n - k];
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    Combination com(200005);

    cout << setprecision(10) << scientific;
    for (int t = 1; t <= T; t++) {
        int w, h, l, u, r, d;
        cin >> w >> h >> l >> u >> r >> d;

        vector <ld> ans;
        for (int i = 1; i < u; i++) {
            if (r == w) break;
            ans.push_back(com.C(r - 1 + i - 1, i - 1) - ((r - 1 + i) * log(2)));
        }
        for (int j = 1; j < l; j++) {
            if (d == h) break;
            ans.push_back(com.C(d - 1 + j - 1, j - 1) - ((d - 1 + j) * log(2)));
        }

        sort(ans.begin(), ans.end());

        ld total = 0.0;
        for (ld x : ans) total += exp(x);

        cout << "Case #" << t << ": " << total << endl;
    }

    return 0;
}