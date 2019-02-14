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
typedef unsigned int uint;
using namespace std;

int N, M, L;
ll inf = 1LL << 60;
typedef pair<int, ll> P;
ll D[2005][2005]; // cost[i][j] -> iからjへの最小コスト
ll truck[2005];
vector<P> G[2005]; // edge[a] is vector of P(b,c) ( witch means [a->b with cost c] )

void dijkstra(int from) {
    priority_queue <P, vector<P>, greater<P>> q;
    for (int i = 0; i < N; i++) {
        D[from][i] = inf;
    }
    D[from][from] = 0;
    q.push(P(0, from));
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        ll y = p.second; // p.second means current node position
        if (D[from][y] != p.first) continue;
        for (int i = 0; i < G[y].size(); i++) {
            int node = G[y].at(i).first; // edge y->node
            ll cost = G[y].at(i).second; // cost of y->node
            if (D[from][node] > D[from][y] + cost) {
                D[from][node] = D[from][y] + cost;
                q.push(P(D[from][node], node)); // P(total cost, current node)
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> L;
    L--;

    for (int i = 0; i < N; i++) {
        cin >> truck[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(P(b,c));
        G[b].push_back(P(a,c));
    }

    for (int i = 0; i < N; i++) {
        dijkstra(i);
    }

    ll mn = inf;
    for (int i = 0; i < N; i++) {
        ll sm = 0;
        for (int j = 0; j < N; j++) {
            sm += 2 * D[i][j] * truck[j];
        }

        ll mx = 0;
        for (int j = 0; j < N; j++) {
            if (truck[j] == 0) continue;

            mx = max(mx, D[i][j] - D[L][j]);
        }

        sm -= mx;
        mn = min(mn, sm);
    }

    cout << mn << "\n";
    return 0;
}