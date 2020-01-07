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

vector <int> edges[100005];

void dfs(vector <int> &dist, int cur, int par, int k = 0) {
    dist[cur] = k;
    for (int ch : edges[cur]) {
        if (ch == par) continue;
        dfs(dist, ch, cur, k + 1);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, u, v;
    cin >> n >> u >> v;
    u--, v--;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector <int> u_dist(n), v_dist(n);
    dfs(u_dist, u, -1);
    dfs(v_dist, v, -1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (u_dist[i] < v_dist[i]) {
            ans = max(ans, v_dist[i] - 1);
        }
    }

    cout << ans << '\n';
    return 0;
}