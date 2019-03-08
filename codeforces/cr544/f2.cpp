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
using namespace std;

int n, m, d, u, v, c;
vector <int> edges[200005];
bool visited[200005];
bool connected_first[200005];

void dfs(int from) {
    for (int to : edges[from]) {
        if (visited[to]) continue;
        visited[to] = true;
        if (from == 0) {
            connected_first[to] = true;
            c++;
        }
        dfs(to);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    visited[0] = true;
    c = 0;
    dfs(0);

    if (edges[0].size() < d || c > d) {
        cout << "NO\n";
        return 0;
    }

    fill(visited, visited+n, false);
    visited[0] = true;
    queue <int> q;

    cout << "YES\n";
    for (int to : edges[0]) {
        if (connected_first[to]) {
            q.push(to);
            cout << 1 << " " << to + 1 << '\n';
            visited[to] = true;
        }
    }

    for (int to : edges[0]) {
        if (c == d) break;
        if (!connected_first[to]) {
            q.push(to);
            cout << 1 << " " << to + 1 << '\n';
            visited[to] = true;
            c++;
        }
    }

    while (q.size()) {
        int from = q.front();
        q.pop();

        for (int to : edges[from]) {
            if (visited[to]) continue;
            q.push(to);
            cout << from + 1 << " " << to + 1 << '\n';
            visited[to] = true;
        }
    }

    return 0;
}