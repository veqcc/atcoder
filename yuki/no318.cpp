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
    vector <int> node, lazy;
    vector <bool> lazyFlag;

public:
    LazySegmentTree(vector <int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, -1);
        lazyFlag.resize(2*n-1, false);
        for (int i = 0; i < n; i++) node[i+n-1] = v[i];
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
        }
    }

    int get(int i, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (r - l == 1 && l == i) return node[k];
        if (i < (l+r)/2) {
            return get(i, 2*k+1, l, (l+r)/2);
        } else {
            return get(i, 2*k+2, (l+r)/2, r);
        }
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n);
    map <int, vector <int> > mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    LazySegmentTree seg(a);
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        int sz = itr->second.size();
        if (sz > 1) {
            seg.update(itr->second[0], itr->second[sz - 1], itr->first);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << max(seg.get(i), a[i]) << " ";
    }

    return 0;
}