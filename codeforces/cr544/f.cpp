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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> edges[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int mx = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (edges[i].size() > mx) {
            mx = edges[i].size();
            idx = i;
        }
    }

    vector <bool> visited(n, false);
    queue <int> q;
    q.push(idx);
    visited[idx] = true;

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