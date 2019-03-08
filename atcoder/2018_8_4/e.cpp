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
using namespace std;

typedef pair <int, int> P;
typedef pair <ll, P> PP;

const ll INF = 1LL << 60;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {-1, 1, 0, 0};
const string mv = "UDRL";

int n, m, k;
string d, s[1005];
int nxt[100005][4]; // Up Down Right Left の順
ll cost[1005][1005];

void dijkstra(int S) {
    priority_queue < PP, vector<PP>, greater<PP> > q;
    fill(cost[0], cost[n], INF);
    cost[S/m][S%m] = 0;
    q.push(PP(0, P(S, k-1)));

    while (q.size()) {
        PP pp = q.top(); q.pop();
        ll c = pp.first;

        P p = pp.second;
        int x = p.first / m;
        int y = p.first % m;
        int idx = p.second;
        if (cost[x][y] < c) continue;

        for (int i = 0; i < 4; i++) {
            if (nxt[idx][i] == -1) continue;

            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
            if (s[next_x][next_y] == '#') continue;

            ll next_cost = c + nxt[idx][i] - idx;
            if (cost[next_x][next_y] > next_cost) {
                cost[next_x][next_y] = next_cost;
                P next_vertex = P(next_x * m + next_y, nxt[idx][i] % k);
                q.push(PP(next_cost, next_vertex));
            }
        }
    }
}

int main() {
    cin >> n >> m >> k >> d;
    for (int i = 0; i < n; i++) cin >> s[i];

    vector <int> idx[4];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            if (d[i] == mv[j]) idx[j].push_back(i);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (idx[i].size()) idx[i].push_back(idx[i][0] + k);
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            if (idx[j].size()) nxt[i][j] = *lower_bound(idx[j].begin(), idx[j].end(), i+1);
            else nxt[i][j] = -1;
        }
    }

    int S, G;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') S = i * m + j;
            if (s[i][j] == 'G') G = i * m + j;
        }
    }

    dijkstra(S);

    ll ans = cost[G/m][G%m];
    if (ans == INF) ans = -1;

    cout << ans << '\n';
    return 0;
}