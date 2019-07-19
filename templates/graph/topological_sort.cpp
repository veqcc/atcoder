#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TopologicalSort {
    int V;
    vector <vector<int>> G;
    vector <bool> used;
    vector <int> indeg; // 入次数
    vector <int> ret;

    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ret.push_back(cur);
            for (int to : G[cur]) {
                indeg[to]--;
                if (indeg[to] == 0 && !used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }

public:
    TopologicalSort(vector<vector<int>> &edge) {
        V = edge.size();
        G = edge;
        used.assign(V, false);
        indeg.assign(V, 0);
    }

    vector<int> build() {
        for (int i = 0; i < V; i++) for (int v : G[i]) indeg[v]++;
        for (int i = 0; i < V; i++) if (indeg[i] == 0 && !used[i]) bfs(i);
        return ret;
    }

    bool isDAG() {
        return ret.size() == V;
    }
};


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A
void AOJ_GRL_4_A() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
    }
    TopologicalSort ts(edge);
    ts.build();
    cout << (ts.isDAG() ? 0 : 1) << '\n';
}


// verified
//   https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
void AOJ_GRL_4_B() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edge(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
    }
    TopologicalSort ts(edge);
    vector <int> dag = ts.build();
    for (int i : dag) cout << i << '\n';
}

int main() {
    AOJ_GRL_4_A();
    // AOJ_GRL_4_B();
    return 0;
}