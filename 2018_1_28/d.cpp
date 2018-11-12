#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef pair < int, int > pii;

const int INF = 1000000007;
const int N = 100005;
int n, m, l, r, d, ans[N];
bool mark[N];
vector < pii > g[N];

void dfs(int v) {
    mark[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].first;
        int len = g[v][i].second;
        if (ans[to] == INF) {
            ans[to] = ans[v] + len;
        }
        if (ans[to] != ans[v] + len) {
            cout << "No";
            exit(0);
        }
        if (!mark[to]) {
            dfs(to);
        }
    }
}

int main() {
    fill(ans, ans+N, INF);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> d;
        g[l].push_back(make_pair(r, d));
        g[r].push_back(make_pair(l, -d));
    }

    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            ans[i] = 0;
            dfs(i);
        }
    }

    cout << "Yes";
    return 0;
}