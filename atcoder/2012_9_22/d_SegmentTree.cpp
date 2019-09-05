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
typedef long double ld;
typedef pair <ld, ld> P;

template <typename T>
class SegmentTree {
    using F = function<T(T, T)>;
    int n;
    F f;
    T t;
    vector <T> dat;

public:
    SegmentTree() {};
    SegmentTree(F f, T t) : f(f), t(t) {}

    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, t);
    }

    void build(const vector <T> &v) {
        auto n_ = (int)v.size();
        init(n_);
        for (int i = 0; i < n_; i++) dat[n + i] = v[i];
        for (int i = n - 1; i > 0; i--) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    void set_val(int k, T x) {
        dat[k += n] = x;
        while (k >>= 1) dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }

    T query(int a, int b) {
        T vl = t, vr = t;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector <ll> p(m);
    vector <ll> p2(m);
    vector <P> ab(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> ab[i].first >> ab[i].second;
        p2[i] = p[i];
    }

    sort(p2.begin(), p2.end());

    int idx = 0;
    map <ll, int> mp;
    for (int i = 0; i < m; i++) {
        if (i && p2[i] == p2[i-1]) continue;
        mp[p2[i]] = idx++;
    }

    auto f = [](P x, P y) {
        return P(x.first * y.first, y.first * x.second + y.second);
    };

    SegmentTree<P> seg(f, P(1.0, 0.0));
    seg.build(vector<P>(idx, P(1.0, 0.0)));

    ld mn = 1.0, mx = 1.0;
    for (int i = 0; i < m; i++) {
        seg.set_val(mp[p[i]], ab[i]);
        P d = seg.query(0, idx);
        ld val = d.first + d.second;
        mn = min(mn, val);
        mx = max(mx, val);
    }

    cout << fixed << setprecision(12) << mn << "\n" << mx << '\n';
    return 0;
}