#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            edge[i].push_back(--v);
        }
    }

    queue<int> q;
    vector <int> dist(n, n);
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int ch : edge[cur]) {
            if (dist[ch] > dist[cur] + 1) {
                dist[ch] = dist[cur] + 1;
                q.push(ch);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << (dist[i] == n ? -1 : dist[i]) << '\n';
    }
    return 0;
}