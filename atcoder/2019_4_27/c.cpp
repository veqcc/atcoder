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

class SegmentTree {
    using F = function<ll(ll, ll)>;
    const F f;
    int n, init;
    vector<int> node;

public:
    SegmentTree(int sz, const F f, ll init) : f(f), init(init) {
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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    SegmentTree seg(n, gcd, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        seg.update(i, a);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, gcd(seg.query(0, i), seg.query(i+1, n)));
    }

    cout << ans << "\n";
    return 0;
}