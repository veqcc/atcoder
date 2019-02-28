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
    vector <int> node, lazy;
    vector <bool> lazyFlag;

public:
    LazySegmentTree(vector <int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);
        for (int i = 0; i < sz; i++) node[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void lazyEvaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            node[k] = lazy[k];
            if (r - l > 1) {
                lazy[k*2+1] = lazy[2*k+2] = lazy[k];
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }

    void update(int a, int b, int val, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = val;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        } else {
            update(a, b, val, 2*k+1, l, (l+r)/2);
            update(a, b, val, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    int find(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    LazySegmentTree seg(vector<int>(N, INF));
    for (int i = 0; i < Q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.update(s, t+1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.find(s, t+1) << "\n";
        }
    }

    return 0;
}