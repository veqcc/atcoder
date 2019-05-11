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

vector <int> edges[200005];
int depth[200005];

int dfs(int cur, int par, int d) {
    depth[cur] = d;

    int mx = d;
    for (int i : edges[cur]) {
        if (i == par) continue;
        mx = max(mx, dfs(i, cur, d + 1));
    }

    return mx;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int l, r;
        cin >> l >> r;
        edges[r].push_back(l);
        edges[l].push_back(r);
    }

    int mx = dfs(1, 0, 1);

    int idx;
    for (int i = 1; i <= n; i++) {
        if (depth[i] == mx) {
            idx = i;
        }
    }

    int d = dfs(idx, 0, 1);

    if ((d + 1) % 3 == 0) {
        cout << "Second\n";
    } else {
        cout << "First\n";
    }

    return 0;
}