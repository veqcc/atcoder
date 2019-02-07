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
typedef pair <int, int> P;

const int N = 1 << 18;

vector <int> pair_list[N];
vector <P> q[N];
int n, m, a[N], ans[N], pos[N], seg[N << 2];

void update(int ind, int l, int r, int w) {
    if (l > w || r < w) return;
    if (l == w && r == w) {
        seg[ind]++;
        return;
    }

    int mid = (l + r) / 2;
    update(ind * 2, l, mid, w);
    update(ind * 2 + 1, mid + 1, r, w);
    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}

int query(int ind, int l, int r, int lw, int rw) {
    if (l > rw || r < lw) return 0;
    if (l >= lw && r <= rw) return seg[ind];

    int mid = (l + r) / 2;
    return query(ind * 2, l, mid, lw, rw) + query(ind * 2 + 1, mid + 1, r, lw, rw);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        q[l].push_back({r, i});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i){
            pair_list[min(pos[i], pos[j])].push_back(max(pos[i], pos[j]));
        }
    }

    for (int i = n; i > 0; i--) {
        for (auto j : pair_list[i]) {
            update(1, 1, n, j);
        }

        for (auto j : q[i]){
            ans[j.second] = query(1, 1, n, 1, j.first);
        }
    }

    for (int i = 1; i <= m; i++){
        cout << ans[i] << "\n";
    }

}