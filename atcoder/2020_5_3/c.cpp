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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<vector<int>> edge(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int high = true;
        for (int to : edge[i]) {
            if (h[to] >= h[i]) {
                high = false;
                break;
            }
        }
        if (high) ans++;
    }

    cout << ans << "\n";
    return 0;
}