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

vector <int> edges[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    ll c[n];
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sm += c[i];
    }

    sort(c, c+n, greater<ll>());
    sm -= c[0];

    queue <int> q;
    q.push(0);

    vector <ll> ans(n, 0);

    int idx = 0;
    while (q.size()) {
        int node = q.front();
        q.pop();

        if (ans[node] > 0) continue;

        ans[node] = c[idx];
        idx++;

        for (auto nxt : edges[node]) {
            if (ans[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    cout << sm << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}