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
#define int long long
using namespace std;
const int INF = 1LL << 60;

struct edge {
    int to, cost;
};

typedef pair <int, int> P;
typedef pair <int, P> PP;
int V, E;
vector <edge> G[100005];
int d[2][100005];
// 0: チケットを使わない最短距離
// 1: チケットを1回使った時の最短距離

void dijkstra() {
    priority_queue<PP, vector<PP>, greater<PP>> q;
    fill(d[0], d[1] + 100005, INF);
    d[0][0] = d[1][0] = 0LL;
    q.push(PP(0LL, P(0, 0)));

    while (!q.empty()) {
        PP p = q.top();
        q.pop();

        int cost = p.first;
        int cur = p.second.first;
        int used = p.second.second;

        if (d[used][cur] < cost) continue;

        for (edge e : G[cur]) {
            if (used == 1) {
                if (d[1][e.to] > d[1][cur] + e.cost) {
                    d[1][e.to] = d[1][cur] + e.cost;
                    q.push(PP(d[1][e.to], P(e.to, 1)));
                }
            } else {
                if (d[0][e.to] > d[0][cur] + e.cost) {
                    d[0][e.to] = d[0][cur] + e.cost;
                    q.push(PP(d[0][e.to], P(e.to, 0)));
                }

                if (d[1][e.to] > d[0][cur]) {
                    d[1][e.to] = d[0][cur];
                    q.push(PP(d[1][e.to], P(e.to, 1)));
                }
            }
        }
    }
}

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back((edge){b, c});
        G[b].push_back((edge){a, c});
    }

    dijkstra();

    for (int i = 0; i < V; i++) {
        cout << d[0][i] + d[1][i] << "\n";
    }

    return 0;
}