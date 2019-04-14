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

vector <int> edges[300005];
int n, op[300005];

int dfs(int cur) {
    if (edges[cur].size() == 0) return 1;

    if (op[cur] == 0) {
        int sm = 0;
        for (int node : edges[cur]) {
            sm += dfs(node);
        }
        return sm;
    } else {
        int mn = 1e9;
        for (int node : edges[cur]) {
            mn = min(mn, dfs(node));
        }
        return mn;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> op[i];
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        edges[par].push_back(i);
    }

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (edges[i].size() == 0) {
            k++;
        }
    }

    cout << k - dfs(1) + 1 << "\n";
    return 0;
}