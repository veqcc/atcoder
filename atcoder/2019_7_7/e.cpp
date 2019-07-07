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

vector <int> edges[100005];
int cnt[100005];
ll k;

ll dfs(int cur, int par) {
    ll ret = max(0LL, k - cnt[par]);
    cnt[cur]++;
    for (int i : edges[cur]) {
        cnt[i]++;
    }

    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        ll d = dfs(nxt, cur);
        ret = ret * d % MOD;
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    fill(cnt, cnt+n, 0LL);
    cout << dfs(0, 0) << "\n";
    return 0;
}