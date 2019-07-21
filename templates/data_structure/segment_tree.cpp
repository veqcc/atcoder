#include <iostream>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;

class SegmentTree {
    const function<ll(ll, ll)> f;
    int n, init;
    vector<int> node;

public:
    SegmentTree(int sz, function<ll(ll, ll)> f, ll init) : f(f), init(init) {
        n = 1;
        while (n < sz) n <<= 1;
        node.assign(2 * n, init);
    }

    void update(int x, ll val) {
        x += n;
        node[x] = val;
        while (x >>= 1) {
            node[x] = f(node[2 * x + 0], node[2 * x + 1]);
        }
    }

    // [a:b)
    ll query(int a, int b) {
        ll l = init, r = init;
        for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if (a & 1) l = f(l, node[a++]);
            if (b & 1) r = f(node[--b], r);
        }
        return f(l, r);
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
void AOJ_DSL_2_A() {
    ll n, q, c, x, y;
    cin >> n >> q;
    SegmentTree seg(n, [](ll a, ll b) { return min(a, b); }, 2147483647LL);
    while (q--) {
        cin >> c >> x >> y;
        if (c) cout << seg.query(x, y + 1) << "\n";
        else seg.update(x, y);
    }
}


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
void AOJ_DSL_2_B() {
    ll n, q, c, x, y;
    cin >> n >> q;
    SegmentTree seg(n, [](ll a, ll b) { return a + b; }, 0);
    while (q--) {
        cin >> c >> x >> y;
        if (c) cout << seg.query(x, y + 1) << "\n";
        else {
            int a = seg.query(x, x + 1);
            seg.update(x, a + y);
        }
    }
}


// verified
//   https://atcoder.jp/contests/abc125/tasks/abc125_c
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
void AtCoder_2019_4_27_C() {
    int n, a;
    cin >> n;
    SegmentTree seg(n, gcd, 0);
    for (int i = 0; i < n; i++) { cin >> a; seg.update(i, a); }
    int ans = 1;
    for (int i = 0; i < n; i++) ans = max(ans, gcd(seg.query(0, i), seg.query(i + 1, n)));
    cout << ans << "\n";
}

int main() {
    // AOJ_DSL_2_A();
    AOJ_DSL_2_B();
    // AtCoder_2019_4_27_C();
    return 0;
}