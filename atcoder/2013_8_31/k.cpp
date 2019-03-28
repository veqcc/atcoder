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
typedef pair <ll, ll> P;

struct SegmentTree {
private:
    int n;
    vector <int> node;

public:
    SegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1, 0);
    }

    void update(int x, int val) {
        x += n - 1;
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int dp[100005];
// leftが小さい順にi個見た時の、マトリョーシカの最大サイズ

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <P> vec(n);
    vector <ll> num;
    for (int i = 0; i < n; i++) {
        ll x, r;
        cin >> x >> r;
        vec[i] = P(x-r, x+r);
        num.push_back(x-r);
        num.push_back(x+r);
    }

    sort(num.begin(), num.end());
    unique(num.begin(), num.end());

    map <ll, int> mp;
    for (int i = num.size() - 1; i >= 0; i--) mp[num[i]] = i;

    sort(vec.begin(), vec.end());

    SegmentTree seg(2 * n + 2);
    for (P p : vec) {
        int left = mp[p.first];
        int right = mp[p.second];
        int mx = seg.getmax(right + 1, 2 * n + 1);
        seg.update(right, mx + 1);
    }

    cout << seg.getmax(0, 2 * n + 1) << '\n';
    return 0;
}