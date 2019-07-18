#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> P;

P dfs(vector<vector<P>> &edge, int cur, int par) {
    P ret = {0, cur};
    for (P &e : edge[cur]) {
        if (e.first == par) continue;
        P cost = dfs(edge, e.first, cur);
        cost.first += e.second;
        ret = max(ret, cost);
    }
    return ret;
}

int tree_diameter(vector<vector<P>> &edge) {
    P root = dfs(edge, 0, -1);
    P diameter = dfs(edge, root.second, -1);
    return diameter.first;
}

// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
void AOJ_GRL_5_A() {
    int n;
    cin >> n;

    vector<vector<P>> edge(n);
    for (int i = 1; i < n; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edge[s].push_back({t, w});
        edge[t].push_back({s, w});
    }

    cout << tree_diameter(edge) << '\n';
}

int main() {
    AOJ_GRL_5_A();
    return 0;
}