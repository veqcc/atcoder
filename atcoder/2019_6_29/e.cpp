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
const int inf = 1000000007;
typedef pair <int, int> P;
typedef pair <int, P> PP;

vector <int> edge[100005];
int dp[100005][3];
// 頂点iにjステップ目でいける最短手数

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        edge[u].push_back(v);
    }

    int s, t;
    cin >> s >> t;
    s--; t--;

    fill(dp[0], dp[n+1], inf);

    priority_queue <PP, vector<PP>, greater<PP> > q;
    dp[s][0] = 0;
    q.push(PP(0, P(s, 0)));

    while (q.size()) {
        PP p = q.top();
        q.pop();

        int cost = p.first;
        int cur = p.second.first;
        int step = p.second.second;

        if (cost > dp[cur][step]) continue;

        for (int v : edge[cur]) {
            if (step < 2) {
                if (dp[v][step+1] > cost) {
                    dp[v][step+1] = cost;
                    q.push(PP(cost, P(v, step+1)));
                }
            } else {
                if (dp[v][0] > cost) {
                    dp[v][0] = cost + 1;
                    q.push(PP(cost + 1, P(v, 0)));
                }
            }
        }
    }

    if (dp[t][0] == inf) {
        cout << -1 << "\n";
    } else {
        cout << dp[t][0] << "\n";
    }

    return 0;
}