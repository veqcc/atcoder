#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

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


// verified
//  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
void AOJ_DSL_2_G() {
    int n, q, c, s, t, x;
    cin >> n >> q;

    // 区間add, 区間sum
    using P = pair<ll, ll>;
    auto f = [](P a, P b) { return P(a.first + b.first, a.second + b.second); };
    auto g = [](P a, ll b) { return P(a.first + b * a.second, a.second); };
    auto h = [](ll a, ll b) { return a + b; };

    LazySegmentTree<P, ll> seg(f, g, h, P(0, 0), 0);
    seg.build(vector<P>(n, P(0, 1)));

    while (q--) {
        cin >> c;
        if (c) {
            cin >> s >> t;
            cout << seg.query(s - 1, t).first << '\n';
        } else {
            cin >> s >> t >> x;
            seg.update(s - 1, t, x);
        }
    }
}


// verified
//  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I&lang=jp
void AOJ_DSL_2_I() {
    int n, q, c, s, t, x;
    cin >> n >> q;

    // 区間update, 区間sum
    using P = pair<ll, ll>;
    auto f = [](P a, P b) { return P(a.first + b.first, a.second + b.second); };
    auto g = [](P a, ll b) { return P(a.second * b, a.second); };
    auto h = [](ll a, ll b) { return b; };

    LazySegmentTree<P, ll> seg(f, g, h, P(0, 0), -1005);
    seg.build(vector<P>(n, P(0, 1)));

    while (q--) {
        cin >> c;
        if (c) {
            cin >> s >> t;
            cout << seg.query(s, t + 1).first << '\n';
        } else {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
    }
}

int main() {
    // AOJ_DSL_2_G();
    AOJ_DSL_2_I();
    return 0;
}