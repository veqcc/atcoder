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
using namespace std;
const int MAX_V = 200005;

int V, E;
vector <int> G[MAX_V], rG[MAX_V], vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int cur) {
    used[cur] = true;
    for (int ch : G[cur]) {
        if (!used[ch]) dfs(ch);
    }
    vs.push_back(cur);
}

void rdfs(int cur, int k) {
    used[cur] = true;
    cmp[cur] = k;
    for (int ch : rG[cur]) {
        if (!used[ch]) rdfs(ch, k);
    }
}

int scc() {
    fill(used, used + V, false);
    vs.clear();
    for (int v = 0; v < V; v++) {
        if(!used[v]) dfs(v);
    }

    fill(used, used + V, false);
    reverse(vs.begin(), vs.end());
    int k = 0;
    for (int v : vs) {
        if (!used[v]) rdfs(v, k++);
    }
    return k;
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        add_edge(s, t);
    }

    scc();

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (cmp[u] == cmp[v]) << "\n";
    }

    return 0;
}