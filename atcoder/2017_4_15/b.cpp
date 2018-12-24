#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
bool visited[100005];
int n, m, a, b;
vector <int> vertex[100005], path, path2;

void dfs(int x) {
    visited[x] = true;
    path.push_back(x);
    for (int i = 0; i < vertex[x].size(); i++) {
        if (!visited[vertex[x][i]]) {
            dfs(vertex[x][i]);
            return;
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    dfs(1);
    swap(path, path2);
    dfs(1);

    cout << path2.size() + path.size() - 1 << "\n";
    for (int i = path.size() - 1; i > 0; i--) {
        cout << path[i] << " ";
    }
    for (int i = 0; i < path2.size(); i++) {
        cout << path2[i] << " ";
    }

    return 0;
}