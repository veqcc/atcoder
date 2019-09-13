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

    vector <int> mn(n);
    vector <P> vec(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mn[i] = min(a, b);
        vec[i] = P(max(a, b), min(a, b));
    }

    sort(vec.begin(), vec.end(), [](const P &x, const P &y) {
        if (x.first == y.first) {
            return x.second < y.second;
        } else {
            return x.first > y.first;
        }
    });

    sort(mn.begin(), mn.end());
    int idx = 1;
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp[mn[i]] == 0) {
            mp[mn[i]] = idx++;
        }
    }

    auto f = [](int x, int y) { return max(x, y); };
    SegmentTree<int> seg(f, 0);
    seg.build(vector<int>(idx, 0));
    for (int i = 0; i < n; i++) {
        int j = mp[vec[i].second];
        int ret = seg.query(j + 1, idx);
        seg.set_val(j, ret + 1);
    }

    cout << seg.query(1, idx) << '\n';
    return 0;
}