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

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int num = 1; num <= n; num++) {
        vector <int> cost(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != num) continue;
                ans += j;
                for (int c = 1; i - j - c >= 0; c++) cost[i - j - c] += c;
                for (int c = 1; i + j + c < n; c++) cost[i + j + c] += c;
            }
        }
        ans += *min_element(cost.begin(), cost.end());
    }

    cout << ans << "\n";
    return 0;
}