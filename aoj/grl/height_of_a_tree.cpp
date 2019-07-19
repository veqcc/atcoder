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
typedef pair <int, int> P;

int dfs(vector<vector<P>> &edge, int cur, int par) {
    int h = 0;
    for (P &e : edge[cur]) {
        if (e.first == par) continue;
        int tmp = dfs(edge, e.first, cur);
        h = max(h, tmp + e.second);
    }
    return h;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<P>> edge(n);
    for (int i = 1; i < n; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[s].push_back({t, w});
        edge[t].push_back({s, w});
    }

    for (int i = 0; i < n; i++) {
        cout << dfs(edge, i, -1) << "\n";
    }

    return 0;
}