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
typedef pair <int, int> P;

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

    int n, q;
    cin >> n >> q;

    vector <P> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    auto f = [](P a, P b) {
        return a.first < b.first ? a : b;
    };

    SegmentTree<P> seg(f, P(n + 1, n + 1));
    seg.build(a);

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;

        if (c == 1) {
            P l_val = seg.query(l - 1, l);
            P r_val = seg.query(r - 1, r);
            seg.set_val(l - 1, P(r_val.first, l));
            seg.set_val(r - 1, P(l_val.first, r));
        } else {
            P ret = seg.query(l - 1, r);
            cout << ret.second << '\n';
        }
    }

    return 0;
}