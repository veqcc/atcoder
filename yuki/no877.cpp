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

template <typename T>
class SegmentTree {
    using F = function<T(T, T)>;
    int n;
    F f;
    T t;
    vector <T> dat;
public:
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

typedef pair <ll, ll> P;

struct Query {
    int l, r;
    ll x;
};

struct Val {
    ll val;
    int type, idx;
    bool operator>(const Val &a) const { return val > a.val; }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, c;
    cin >> n >> q;

    vector <ll> a(n);
    vector <Query> Q(q);
    vector <Val> v(n + q);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = {a[i], 0, i};
    }
    for (int i = 0; i < q; i++) {
        cin >> c >> Q[i].l >> Q[i].r >> Q[i].x;
        v[n + i] = {Q[i].x, 1, i};
    }

    sort(v.begin(), v.end(), greater<Val>());

    auto f = [](P a, P b) { return P(a.first + b.first, a.second + b.second); };
    SegmentTree<P> seg(f, P(0, 0));
    seg.build(vector<P>(n, P(0, 0)));

    vector <ll> ans(q);
    for (int i = 0; i < n + q; i++) {
        if (v[i].type == 0) {
            seg.set_val(v[i].idx, {v[i].val, 1});
        } else {
            int idx = v[i].idx;
            P ret = seg.query(Q[idx].l - 1, Q[idx].r);
            ans[idx] = ret.first - v[i].val * ret.second;
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
    return 0;
}