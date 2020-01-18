#include <functional>
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
typedef pair<int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> d(n);
    vector <P> d_sort(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        d_sort[i] = P(d[i], i);
    }

    sort(d_sort.begin(), d_sort.end());

    vector < vector <P> > edge(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(P(i, v));
        edge[v].push_back(P(i, u));
    }

    vector <int> color(n, -1);
    vector <int> ans(m, 1000000000);

    vector <int> visited(n, false);
    for (int i = 0; i < n; i++) {
        int idx = d_sort[i].second;
        if (visited[idx]) continue;

        bool exist = false;
        for (P p : edge[idx]) {
            if (visited[p.second]) {
                color[idx] = (color[p.second] + 1) % 2;
                visited[idx] = true;
                exist = true;
                ans[p.first] = d_sort[i].first;
                break;
            }
        }

        if (!exist) {
            bool ok = false;

            for (P p : edge[idx]) {
                if (d[p.second] == d_sort[i].first) {
                    ok = true;
                    ans[p.first] = d[p.second];
                    color[idx] = 0;
                    visited[idx] = true;
                    color[p.second] = 1;
                    visited[p.second] = true;
                    break;
                }
            }

            if (!ok) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            cout << 'B';
        } else {
            cout << 'W';
        }
    }

    cout << '\n';
    for (int i = 0; i < m; i++) cout << ans[i] << '\n';

    return 0;
}