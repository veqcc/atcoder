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
typedef pair <int, int> P;

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

    int n;
    cin >> n;

    vector <P> xd(n);
    for (int i = 0; i < n; i++) cin >> xd[i].first >> xd[i].second;

    sort(xd.begin(), xd.end());

    vector <int> x(n);
    for (int i = 0; i < n; i++) x[i] = xd[i].first;

    vector <int> nxt(n);
    for (int i = 0; i < n; i++) nxt[i] = i;

    auto f = [](int a, int b) { return max(a, b); };
    SegmentTree<int> seg(f, 0);
    seg.build(nxt);

    for (int i = n - 2; i >= 0; i--) {
        int idx = lower_bound(x.begin(), x.end(), x[i] + xd[i].second) - x.begin();
        int mx = seg.query(i, idx);
        seg.set_val(i, mx);
    }

    vector <ll> dp(n + 1, 1);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1] + dp[seg.query(i, i + 1) + 1];
        dp[i] %= MOD;
    }

    cout << dp[0] << "\n";
    return 0;
}