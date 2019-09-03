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

int C[1005], ans;
vector<int> edge[1005];

int dfs(int cur, int par) {
    if (edge[cur].size() == 0) {
        return C[cur];
    }

    vector <int> children;
    for (auto ch : edge[cur]) {
        if (ch == par) continue;
        children.push_back(dfs(ch, cur));
    }

    int mn = *min_element(children.begin(), children.end());
    for (int ch : children) {
        ans += ch - mn;
    }

    return mn;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        edge[p].push_back(i);
    }

    fill(C, C + n, 0);
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        C[b] = c;
    }

    ans = 0;
    ans += dfs(0, -1) * edge[0].size();

    cout << ans << "\n";
    return 0;
}