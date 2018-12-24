#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int size = 50;
int n, m;
bool graph[size][size];
bool visited[size];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == true && visited[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    int a[m], b[m];

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
        fill(visited, visited+n, false);

        dfs(0);

        bool bridge = false;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false) {
                bridge = true;
            }
        }

        if (bridge) {
            ans++;
        }

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    cout << ans << endl;
    return 0;
}