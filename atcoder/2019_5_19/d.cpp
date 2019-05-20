#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
typedef pair <int, int> P;

vector <P> edges[100005];
vector <int> color(100005);

void dfs(int cur, int par, int c) {
    color[cur] = c;

    for (P p : edges[cur]) {
        int nxt = p.first;
        int w = p.second;

        if (nxt == par) continue;

        if (w % 2 == 0) {
            dfs(nxt, cur, c);
        } else {
            dfs(nxt, cur, (c + 1) % 2);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[u].push_back(P(v, w));
        edges[v].push_back(P(u, w));
    }

    dfs(0, -1, 0);

    for (int i = 0; i < n; i++) {
        cout << color[i] << "\n";
    }

    return 0;
}