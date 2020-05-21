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

    vector<int> p(n);
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] > 0) edge[--p[i]].push_back(i);
    }

    auto dfs = [&](auto dfs, int cur) -> int {
        int depth = 0;
        for (int ch : edge[cur]) {
            depth = max(depth, dfs(dfs, ch));
        }
        return depth + 1;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
            ans = max(ans, dfs(dfs, i));
        }
    }

    cout << ans << "\n";
    return 0;
}