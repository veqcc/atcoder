#include <functional>
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

vector <int> edges[200005];
vector <ll> counter(200005);

void dfs(int cur, int par) {
    for (int e : edges[cur]) {
        if (e == par) continue;
        counter[e] += counter[cur];
        dfs(e, cur);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q, a, b, p;
    ll x;
    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int q = 0; q < Q; q++) {
        cin >> p >> x;
        counter[p] += x;
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        cout << counter[i] << ' ';
    }

    return 0;
}
