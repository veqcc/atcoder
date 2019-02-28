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

int N, Q;

struct SegmentTree {
private:
    int n;
    vector <int> node;

public:
    SegmentTree(vector <int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1, 0);
    }

    void add(int x, int val) {
        x += n - 1;
        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }

    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    SegmentTree seg(vector<int>(N, 0));
    for (int i = 0; i < Q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            seg.add(x-1, y);
        } else {
            cout << seg.getsum(x-1, y) << "\n";
        }
    }

    return 0;
}