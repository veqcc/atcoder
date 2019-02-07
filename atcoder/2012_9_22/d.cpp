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
typedef unsigned int uint;
using namespace std;
typedef pair <double, double> pdd;
typedef pair <ll, pdd> pidd;

pdd dat[1 << 18];

void update(int node, pdd a) {
    node += 1 << 17;
    dat[node] = a;
    for (;;) {
        node /= 2;
        if (node == 0) break;
        dat[node] = make_pair(dat[node*2].first * dat[node*2+1].first,
                              dat[node*2].second * dat[node*2+1].first + dat[node*2+1].second);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    ll n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < 1 << 17; i++) {
        update(i, make_pair(1.0, 0.0));
    }

    vector <pidd> vec;
    vector <ll> prs;
    for (int i = 0; i < m; i++) {
        ll p;
        double a, b;
        cin >> p >> a >> b;
        vec.push_back(make_pair(p, make_pair(a, b)));
        prs.push_back(p);
    }

    sort(prs.begin(), prs.end());

    vector <ll> uni;
    ll now = -1;
    for (int i = 0; i < m; i++) {
        if (now != prs[i]) {
            uni.push_back(prs[i]);
            now = prs[i];
        }
    }
    prs = uni;

    double mx, mn;
    mx = mn = dat[1].first + dat[1].second;
    for (int i = 0; i < m; i++) {
        int low = lower_bound(prs.begin(), prs.end(), vec[i].first) - prs.begin();
        update(low, vec[i].second);
        mx = max(mx, dat[1].first + dat[1].second);
        mn = min(mn, dat[1].first + dat[1].second);
    }

    cout << fixed << setprecision(12) << mn << "\n" << mx << "\n";
    return 0;
}