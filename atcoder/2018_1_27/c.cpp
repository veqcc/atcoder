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

int r, c, V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int res = 0;
    fill(match, match + MAX_V, -1);
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) {
            fill(used, used + MAX_V, false);
            if (dfs(v)) res++;
        }
    }
    return res;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c;
    string s[r];
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '.') ans++;

            if (i < r - 1) {
                if (s[i][j] == '.' && s[i + 1][j] == '.') {
                    add_edge(i * c + j, (i + 1) * c + j);
                }
            }
            if (j < c - 1) {
                if (s[i][j] == '.' && s[i][j + 1] == '.') {
                    add_edge(i * c + j, i * c + j + 1);
                }
            }
        }
    }

    V = r * c;
    cout << ans - bipartite_matching()<< endl;
    return 0;
}