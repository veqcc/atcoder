#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

bool visited[100005];
ll value[100005];
vector < pair<int,ll> > vec[100005];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < vec[v].size() ; i++) {
        if (visited[vec[v][i].first] == false) {
            value[vec[v][i].first] = vec[v][i].second + value[v];
            dfs(vec[v][i].first);
        }
    }
}

int main() {
    int n, a, b, q, k, x, y;
    ll c;

    cin >> n;
    fill(visited, visited+n, false);

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        vec[a].push_back(make_pair(b, c));
        vec[b].push_back(make_pair(a, c));
    }

    cin >> q >> k;
    value[k] = 0;
    dfs(k);

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << value[x] + value[y] << endl;
    }

    return 0;
}