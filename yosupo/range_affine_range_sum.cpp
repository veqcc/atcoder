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
const ll MOD = 998244353LL;

template <typename T, typename E>
class LazySegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    int n, height;
    F f;
    G g;
    H h;
    T t;
    E e;
    vector<T> dat;
    vector<E> laz;

public:
    LazySegmentTree(F f, G g, H h, T t, E e): f(f), g(g), h(h), t(t), e(e) {}

    void init(int n_) {
        n = 1;
        height = 0;
        while (n < n_) { n <<= 1; height++; }
        dat.assign(2 * n, t);
        laz.assign(2 * n, e);
    }

    void build(const vector<T> &v) {
        auto n_ = (int)v.size();
        init(n_);
        for (int i = 0; i < n_; i++) dat[n + i] = v[i];
        for (int i = n - 1; i > 0; i--) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    inline T reflect(int k) {
        return laz[k] == e ? dat[k] : g(dat[k], laz[k]);
    }

    inline void eval(int k) {
        if (laz[k] == e) return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = e;
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) {
            eval(k >> i);
        }
    }

    inline void recalc(int k) {
        while (k >>= 1) {
            dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
        }
    }

    void update(int a, int b, E x) {
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), l++;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
        recalc(a);
        recalc(b);
    }

    void set_val(int a, T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = e;
        recalc(a);
    }

    T query(int a, int b) {
        thrust(a += n);
        thrust(b += n - 1);
        T vl = t, vr = t;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    using P = pair<ll, ll>;
    auto f = [](P a, P b) { return P((a.first + b.first) % MOD, (a.second + b.second) % MOD); };
    auto g = [](P a, P b) { return P((a.first * b.first + a.second * b.second) % MOD, a.second); };
    auto h = [](P a, P b) { return P(a.first * b.first % MOD, (a.second * b.first + b.second) % MOD); };

    LazySegmentTree<P, P> seg(f, g, h, P(0, 1), P(1, 0));

    vector <P> a(n, P(0, 1));
    for (int i = 0; i < n; i++) cin >> a[i].first;

    seg.build(a);

    while (q--) {
        int c;
        cin >> c;
        if (c == 0) {
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.update(l, r, P(b, c));
        } else {
            ll l, r;
            cin >> l >> r;
            cout << seg.query(l, r).first << endl;
        }
    }

    return 0;
}