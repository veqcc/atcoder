#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair <int, int> P;

class LowLink {
    const vector<vector<int>> edge;
    vector <bool> used;
    vector <int> ord; // DFS木で訪れた順
    vector <int> low; // 後退辺を1度だけ通って辿れるordの最小値

public:
    vector <int> articulation; // 関節点
    vector <P> bridge; // 橋

    LowLink(const vector<vector<int>> &edge) : edge(edge) {}

    int dfs(int cur, int k, int par) {
        used[cur] = true;
        ord[cur] = k++;
        low[cur] = ord[cur];
        bool is_articulation = false;
        int children = 0;
        for (int to : edge[cur]) {
            if (!used[to]) {
                children++;
                k = dfs(to, k, cur);
                low[cur] = min(low[cur], low[to]);
                if (par >= 0) is_articulation |= low[to] >= ord[cur];
                if (low[to] > ord[cur]) bridge.push_back({cur, to});
            } else if (to != par) {
                low[cur] = min(low[cur], ord[to]);
            }
        }
        if (par == -1) is_articulation |= children > 1;
        if (is_articulation) articulation.push_back(cur);
        return k;
    }

    void build() {
        used.assign(edge.size(), false);
        ord.assign(edge.size(), 0);
        low.assign(edge.size(), 0);
        for (int i = 0; i < edge.size(); i++) {
            if (!used[i]) dfs(i, 0, -1);
        }
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp
void AOJ_GRL_3_A() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }

    LowLink lowlink(edge);
    lowlink.build();

    sort(lowlink.articulation.begin(), lowlink.articulation.end());
    for (int i : lowlink.articulation) cout << i << '\n';
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=jp
void AOJ_GRL_3_B() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        edge[t].push_back(s);
    }

    LowLink lowlink(edge);
    lowlink.build();

    vector <P> bridge = lowlink.bridge;
    for (P &p : bridge) if (p.first > p.second) swap(p.first, p.second);
    sort(bridge.begin(), bridge.end());
    for (P p : bridge) cout << p.first << " " << p.second << '\n';
}

int main() {
    AOJ_GRL_3_A();
    // AOJ_GRL_3_B();
    return 0;
}