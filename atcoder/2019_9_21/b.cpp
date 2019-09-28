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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    auto f = [](int a, int b) {
        return a + b;
    };

    vector <int> small(n);
    SegmentTree<int> seg1(f, 0);
    seg1.build(vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        if (i >= k) seg1.set_val(p[i - k], 0);
        seg1.set_val(p[i], 1);
        small[i] = seg1.query(p[i] + 1, n);
    }

    vector <int> big(n);
    SegmentTree<int> seg2(f, 0);
    seg2.build(vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - k) seg2.set_val(p[i + k], 0);
        seg2.set_val(p[i], 1);
        big[i] = seg2.query(0, p[i]);
    }

    int ans = 0;
    int d = 0;

    int cur = 0;
    for (int i = 0; i < k; i++) cur += small[i];
    if (cur) {
        ans++;
    } else {
        d = 1;
    }

    for (int i = k; i < n; i++) {
        bool flag = false;

        if (small[i]) {
            cur += small[i];
            flag = true;
            cur -= big[i - k];
        } else {
            if (big[i - k]) {
                cur -= big[i - k];
                if (cur) {
                    flag = true;
                }
            }
        }

        if (cur == 0) d = 1;
        if (flag) ans++;
    }

    cout << ans + d << '\n';
    return 0;
}