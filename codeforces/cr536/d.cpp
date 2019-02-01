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

bool checked[100005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> G[n];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    checked[0] = true;
    priority_queue <int, vector<int>, greater<int>> q;
    q.push(0);
    while (q.size()) {
        int cur = q.top();
        q.pop();
        cout << cur + 1 << " ";

        for (int i = 0; i < G[cur].size(); i++) {
            if (!checked[G[cur][i]]) {
                q.push(G[cur][i]);
                checked[G[cur][i]] = true;
            }
        }
    }

    return 0;
}