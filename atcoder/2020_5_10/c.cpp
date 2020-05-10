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

    int n, m, x;
    cin >> n >> m >> x;

    vector <int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
        int cost = 0;
        vector <int> sum(m);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cost += c[j];
                for (int k = 0; k < m; k++) {
                    sum[k] += a[j][k];
                }
            }
        }

        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (sum[j] < x) {
                ok = false;
            }
        }

        if (ok) {
            ans = min(ans, cost);
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";
    return 0;
}