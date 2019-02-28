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

const int INF = 2147483647;
int N, Q;

struct LazySegmentTree {
private:
    int n;
    vector <ll> node, lazy;

public:
    LazySegmentTree(vector <ll> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        for (int i = 0; i < sz; i++) node[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--) node[i] = node[2*i+1] + node[2*i+2];
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

    void add(int a, int b, int val, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += val * (r - l);
            eval(k, l, r);
        } else {
            add(a, b, val, 2*k+1, l, (l+r)/2);
            add(a, b, val, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    LazySegmentTree seg(vector<ll>(N, 0));
    for (int i = 0; i < Q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            seg.add(s-1, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.getsum(s-1, t) << "\n";
        }
    }

    return 0;
}