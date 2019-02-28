#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

struct LazySegmentTree {
private:
    int n;
    vector <ll> node, lazy;

public:
    LazySegmentTree(vector <ll> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] > 0) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += r - l;
            eval(k, l, r);
        } else {
            add(a, b, 2*k+1, l, (l+r)/2);
            add(a, b, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll get(int i, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (i < l || r <= i) return 0;
        if (r - l == 1 && l == i) return node[k];
        ll vl = get(i, 2*k+1, l, (l+r)/2);
        ll vr = get(i, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    LazySegmentTree seg(vector <ll>(n, 0));
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        seg.add(l-1, r);
    }

    for (int i = 0; i < n; i++) {
        if (seg.get(i) % 2 == 0) cout << 0;
        else cout << 1;
    }

    cout << "\n";
    return 0;
}