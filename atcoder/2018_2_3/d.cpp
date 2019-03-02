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
typedef pair <ll, int> P;

class UnionFind {
    vector<int> par;
    int n;
public:
    UnionFind(int n) : par(n, -1) {}
    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    if ((n - 1 - m) * 2 > n) {
        cout << "Impossible\n";
        return 0;
    }

    vector <priority_queue < ll, vector<ll>, greater<ll> > > q(n);
    set <int> st;
    for (int i = 0; i < n; i++) {
        int par = uf.find(i);
        q[par].push(a[i]);
        st.insert(par);
    }

    vector <int> parents;
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        parents.push_back(*itr);
    }

    int sz = parents.size();
    if (sz == 1) {
        cout << 0 << "\n";
        return 0;
    }

    ll ans = 0;
    for (int par : parents) {
        ans += q[par].top();
        q[par].pop();
    }

    priority_queue < P, vector<P>, greater<P> > Q;
    for (int par : parents) {
        if (q[par].size()) {
            ll p = q[par].top();
            q[par].pop();
            Q.push(P(p, par));
        }
    }

    for (int i = 0; i < sz - 2; i++) {
        P p = Q.top();
        Q.pop();
        ans += p.first;
        int pa = p.second;
        if (q[pa].size()) {
            int t = q[pa].top();
            q[pa].pop();
            Q.push(P(t, pa));
        }
    }

    cout << ans << "\n";
    return 0;
}