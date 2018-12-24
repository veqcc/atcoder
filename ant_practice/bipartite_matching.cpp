#include <algorithm>
#include <iostream>
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
const int MAX_V=2000;

int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

// 増加道を探す
bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];

        // どの頂点ともまだマッチしていない or
        // マッチしてるけどその頂点からdfsしたらまだマッチしていない頂点にたどり着ける
        if (w < 0 || (!used[w] && dfs(w))) {

            // パスを入れ替えちゃう
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

// 二部グラフの最大マッチングを返す
int bipartite_matching() {
    int res = 0;
    fill(match, match + MAX_V, -1);
    for (int v = 0; v < V; v++) {

        // vから増加道があったらマッチングを1増やす
        if (match[v] < 0) {
            fill(used, used + MAX_V, false);
            if (dfs(v)) res++;
        }
    }
    return res;
}

int main() {
    V = 3;
    bipartite_matching();
    return 0;
}