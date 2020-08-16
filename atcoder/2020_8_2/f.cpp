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

typedef pair<int, int> P;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    auto f = [](int a, int b) { return a + b; };
    SegmentTree<int> seg(f, 0);
    seg.build(vector<int>(n, 0));

    vector<int> l(q);
    vector<P> query(q);
    for (int i = 0; i < q; i++) {
        int r;
        cin >> l[i] >> r;
        l[i]--;
        query[i] = {r, i};
    }
    sort(query.begin(), query.end());

    map<int, int> right;
    for (int i = 1; i <= n; i++) {
        right[i] = -1;
    }

    vector<int> ans(q);

    int cur = 0;
    for (auto p : query) {
        int r = p.first, idx = p.second;
        for (; cur < r; cur++) {
            int color = c[cur];
            seg.set_val(cur, 1);
            if (right[color] != -1) {
                seg.set_val(right[color], 0);
            }
            right[color] = cur;
        }

        ans[idx] = seg.query(l[idx], r);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}