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

    void add(int x, int val) {
        x += n - 1;
        node[x] += val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
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

    int n, Q;
    cin >> n >> Q;

    SegmentTree seg(n);
    for (int i = 0; i < n; i++) {
        int A;
        cin >> A;
        seg.add(i, A);
    }

    set <int> st;
    for (int i = 0; i <= n; i++) st.insert(i);


    for (int q = 0; q < Q; q++) {
        int query, x;
        cin >> query >> x;

        if (query == 1) {
            st.erase(x);
        } else if (query == 2) {
            st.insert(x);
        } else if (query == 3) {
            seg.add(x - 1, 1);
        } else {
            auto itr = st.lower_bound(x);
            int r = *itr;
            itr--;
            int l = *itr;
            cout << seg.getsum(l, r) << "\n";
        }
    }

    return 0;
}