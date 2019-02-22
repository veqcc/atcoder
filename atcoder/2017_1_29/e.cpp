#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

struct edge {
    int to, cost, type;
};

const int INF = 1 << 30;
int n, a, b, c, d, dist[100005], rev[100005];
vector <edge> G[100005];

void dfs(int cur, int par) {
    for (auto e : G[cur]) {
        if (e.to == par) continue;
        dfs(e.to, cur);
        dist[cur] = max(dist[cur], dist[e.to] + e.cost);
        rev[cur] += rev[e.to] + e.type;
    }
}

int dfs2(int cur, int par, int par_cost, int par_weight) {
    vector <int> vec;
    vec.push_back(0);
    int rev_sm = 0;
    for (auto e : G[cur]) {
        if (e.to == par) {
            vec.push_back(par_cost + e.cost);
            rev_sm += par_weight + e.type;
        } else {
            vec.push_back(dist[e.to] + e.cost);
            rev_sm += rev[e.to] + e.type;
        }
    }

    sort(vec.begin(), vec.end(), greater<int>());
    int ret = INF;
    if (vec[0] <= d) ret = rev_sm;

    for (auto e : G[cur]) {
        if (e.to == par) continue;
        ret = min(ret, dfs2(e.to, cur, vec[vec[0] == dist[e.to] + e.cost], rev_sm - rev[e.to] - e.type));
    }

    return ret;
}

int main() {
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back((edge){b, c, 1});
        G[b].push_back((edge){a, c, 0});
    }

    dfs(0, 0);
    int ret = dfs2(0, 0, 0, 0);

    if (ret == INF) cout << -1 << "\n";
    else cout << ret << "\n";

    return 0;
}