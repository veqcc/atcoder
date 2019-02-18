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
typedef pair<int, int> P;

int n, u, v;
bool visited[100005];
vector <int> edge[100005];

P dfs(int x) {
    visited[x] = true;
    P ret = P(1, 0);
    for (int i: edge[x]) {
        if (visited[i]) continue;
        P p = dfs(i);
        ret.first += max(p.first - 1, p.second);
        ret.second += max(p.first, p.second);
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    P p = dfs(1);
    cout << max(p.first, p.second) << "\n";
    return 0;
}