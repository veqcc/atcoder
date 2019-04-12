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
typedef pair <int, int> P;

vector <int> edges[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        edges[p].push_back(q);
        edges[q].push_back(p);
    }

    int Q;
    cin >> Q;

    for (int x = 0; x < Q; x++) {
        int a;
        cin >> a;
        a--;

        priority_queue <P, vector<P>, greater<P>> q;
        q.push(P(0, a));

        vector <bool> visited(n, false);
        visited[a] = true;

        vector <int> cost(n, 1e9);
        cost[a] = 0;

        while (q.size()) {
            int now = q.top().second;
            int c = q.top().first;
            q.pop();
            if (cost[now] < c) continue;
            for (int node : edges[now]) {
                visited[node] = true;
                if (cost[node] > c + 1) {
                    cost[node] = c + 1;
                    q.push(P(c+1, node));
                }
            }
        }

        int cnt = -1;
        for (bool v : visited) if (v) cnt++;

        int depth = 0;
        for (int c : cost) if (c < 1e9) depth = max(depth, c);

        int ret = 0;
        while ((1 << ret) < depth) ret++;

        cout << cnt << " " << ret << "\n";
    }

    return 0;
}