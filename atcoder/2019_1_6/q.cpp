#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

struct SegmentTree {
private:
    int n;
    vector <ll> node;

public:
    SegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1, 0);
    }

    void update(int x, ll val) {
        x += n - 1;
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, h;
    cin >> n;

    vector <P> flower(n);
    for (int i = 0; i < n; i++) {
        cin >> h;
        flower[i] = P(h, i);
    }

    sort(flower.begin(), flower.end());

    vector <ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    SegmentTree seg(n);
    for (int i = 0; i < n; i++) {
        int idx = flower[i].second;
        seg.update(idx, A[idx] + seg.getmax(0, idx));
    }

    cout << seg.getmax(0, n) << "\n";
    return 0;
}