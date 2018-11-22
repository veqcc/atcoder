#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

bool visited[100005];
int value[2][100005];
vector <int> vec[100005];

void dfs(int v, int t) {
    visited[v] = true;
    for (int i = 0; i < vec[v].size() ; i++) {
        if (visited[vec[v][i]] == false) {
            value[t][vec[v][i]] = 1 + value[t][v];
            dfs(vec[v][i], t);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;

    fill(value[0], value[1]+100005, 0);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    fill(visited, visited+100005, false);
    dfs(1, 0);
    fill(visited, visited+100005, false);
    dfs(n, 1);

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (value[0][i] <= value[1][i]) {
            count++;
        }
    }

    if (2 * count <= n) {
        cout << "Snuke" << endl;
    } else {
        cout << "Fennec" << endl;
    }

    return 0;
}