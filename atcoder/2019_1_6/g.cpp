#include <algorithm>
#include <iostream>
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

vector <int> G[100005];
int dp[100005];

void dfs(int x, int y) {
    if (dp[x] < y) {
        dp[x] = y;
        for (int i = 0; i < G[x].size(); i++) {
            dfs(G[x][i], y+1);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool start[n];
    fill(start, start+n, true);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        start[y] = false;
    }

    for (int i = 0; i < n; i++) {
        if (start[i]) dfs(i, 1);
    }

    cout << *max_element(dp, dp+100005) - 1 << "\n";
    return 0;
}