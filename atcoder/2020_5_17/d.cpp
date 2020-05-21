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

    vector<vector<int>> edge(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    cout << "Yes" << '\n';

    vector<int> ans(n);

    queue<int> q;
    vector<bool> visited(n, false);

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int ch : edge[cur]) {
            if (visited[ch]) continue;
            visited[ch] = true;
            ans[ch] = cur;
            q.push(ch);
        }
    }

    for (int i = 1; i < n; i++) {
        cout << ans[i] + 1 << '\n';
    }

    return 0;
}