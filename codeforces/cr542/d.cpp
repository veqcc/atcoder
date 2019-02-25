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

const int inf = 1 << 30;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> candy[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        candy[a].push_back(b);
    }

    int cost[n];
    fill(cost, cost+n, 0);
    for (int i = 0; i < n; i++) {
        if (candy[i].size() > 0) cost[i] = inf;

        for (int j = 0; j < candy[i].size(); j++) {
            cost[i] = min(cost[i], (candy[i][j] + n - i) % n);
        }

        cost[i] += (candy[i].size() - 1) * n;
    }

    for (int i = 0; i < n; i++) { // i番目から出発した時
        int ret = 0;
        for (int j = 0; j < n; j++) {
            ret = max(ret, j + cost[(i+j)%n]);
        }
        cout << ret << " ";
    }

    return 0;
}