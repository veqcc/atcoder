#include <iostream>
#include <functional>
#include <vector>
using namespace std;
typedef long long ll;

// 区間可算・区間和クエリ

struct LazySegmentTree {
    int n;
    vector <ll> node, lazy;

public:
    LazySegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[2 * k + 1] += lazy[k] / 2;
                lazy[2 * k + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += x * (r - l);
            eval(k, l, r);
        } else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];
        }
    }

    ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        eval(k, l, r);
        if (a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};


// verified
//   http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
void AOJ_DSL_2_G() {
    int N, Q, q, s, t, x;
    cin >> N >> Q;
    LazySegmentTree seg(N);
    while (Q--) {
        cin >> q;
        if (q) {
            cin >> s >> t;
            cout << seg.getsum(s - 1, t) << '\n';
        } else {
            cin >> s >> t >> x;
            seg.add(s - 1, t, x);
        }
    }
}

int main() {
    AOJ_DSL_2_G();
    return 0;
}