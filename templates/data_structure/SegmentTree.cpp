#include <iostream>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;

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


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
void AOJ_DSL_2_A() {
    ll n, q, c, x, y;
    cin >> n >> q;

    // 1点更新、区間min
    auto f = [](int a, int b) { return min(a, b); };
    SegmentTree<int> seg(f, 2147483647);
    seg.build(vector<int>(n, 2147483647));
    while (q--) {
        cin >> c >> x >> y;
        if (c) cout << seg.query(x, y + 1) << "\n";
        else seg.set_val(x, y);
    }
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
void AOJ_DSL_2_B() {
    ll n, q, c, x, y;
    cin >> n >> q;

    // 1点加算、区間sum
    auto f = [](ll a, ll b) { return a + b; };
    SegmentTree<ll> seg(f, 0LL);
    seg.build(vector<ll>(n, 0LL));
    while (q--) {
        cin >> c >> x >> y;
        if (c) cout << seg.query(x - 1, y) << "\n";
        else seg.set_val(x - 1, seg.query(x - 1, x) + y);
    }
}


// verified
//   https://atcoder.jp/contests/abc125/tasks/abc125_c
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
void AtCoder_2019_4_27_C() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 更新なし、区間gcd
    SegmentTree<int> seg(gcd, 0);
    seg.build(a);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, gcd(seg.query(0, i), seg.query(i + 1, n)));
    }
    cout << ans << "\n";
}

int main() {
    // AOJ_DSL_2_A();
    // AOJ_DSL_2_B();
    AtCoder_2019_4_27_C();
    return 0;
}