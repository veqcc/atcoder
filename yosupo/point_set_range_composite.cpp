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
const ll MOD = 998244353;

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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    auto f = [](P a, P b) {
        ll x = a.first * b.first % MOD;
        ll y = (b.first * a.second + b.second) % MOD;
        return P(x, y);
    };
    SegmentTree<P> seg(f, P(1, 0));

    vector <P> vec(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        vec[i] = P(a, b);
    }

    seg.build(vec);

    while (q--) {
        ll t, x, y, z;
        cin >> t >> x >> y >> z;

        if (t == 0) {
            seg.set_val(x, P(y, z));
        } else {
            P p = seg.query(x, y);
            cout << (p.first * z + p.second) % MOD << endl;
        }
    }

    return 0;
}