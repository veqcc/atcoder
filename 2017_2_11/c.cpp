#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N = 8;
bool G[MAX_N][MAX_N];

int dfs(int v, int n, bool visited[MAX_N]) {
    bool all_visited = true;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            all_visited = false;
        }
    }

    if (all_visited) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (G[v][i] == false) continue;
        if (visited[i]) continue;
        visited[i] = true;
        ret += dfs(i, n, visited);
        visited[i] = false;
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = true;
    }

    bool visited[MAX_N];
    fill(visited, visited+MAX_N, false);
    visited[0] = true;
    cout << dfs(0, n, visited);
    return 0;
}