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

    int n, m, d, a;
    cin >> n >> m >> d;

    vector <int> init(n);
    for (int i = 0; i < n; i++) init[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a;
        swap(init[a], init[a - 1]);
    }

    vector <vector<int>> next(30, vector<int>(n));
    for (int i = 0; i < n; i++) next[0][init[i]] = i;

    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < n; j++) {
            next[i + 1][j] = next[i][next[i][j]];
        }
    }

    for (int i = 0; i < n; i++) {
        int ans = i;
        for (int j = 0; j < 30; j++) {
            if (d & (1 << j)) {
                ans = next[j][ans];
            }
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}