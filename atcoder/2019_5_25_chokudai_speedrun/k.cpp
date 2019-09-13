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

typedef pair <int, int> P;

P dfs(vector<vector<int>> &edge, vector<bool> &visited, int cur, int par) {
    int v = 1, e = 0;
    visited[cur] = true;
    for (int ch : edge[cur]) {
        if (ch == par) continue;
        if (visited[ch]) {
            e++;
            continue;
        }
        P p = dfs(edge, visited, ch, cur);
        v += p.first;
        e += p.second + 1;
    }
    return P(v, e);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int idx = 1;
    map<int, int> mp;

    vector<vector<int>> edge(2 * n + 2);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (mp[a] == 0) mp[a] = idx++;
        if (mp[b] == 0) mp[b] = idx++;
        edge[mp[a]].push_back(mp[b]);
        edge[mp[b]].push_back(mp[a]);
    }

    int ans = 0;
    vector <bool> visited(2 * n + 2);
    for (int i = 1; i < idx; i++) {
        if (!visited[i]) {
            P p = dfs(edge, visited, i, -1);
            ans += min(p.first, p.second);
        }
    }

    cout << ans << "\n";
    return 0;
}