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

vector < vector <int> > edge(100005);
vector <bool> visited(100005);

void dfs(int cur) {
    visited[cur] = 1;
    for (int nxt : edge[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int isolated_count = 0;
    int have_one_edge = 0;
    int separated_count = 0;
    for (int i = 0; i < n; i++) {
        if (edge[i].size() == 0) {
            isolated_count++;
        } else if (edge[i].size() == 1) {
            have_one_edge++;
        }

        if (!visited[i]) {
            separated_count++;
            dfs(i);
        }
    }

    if (separated_count > 2) {
        cout << "Alice" << '\n';
    } else if (separated_count == 2) {
        if (isolated_count == 0) {
            cout << "Alice" << '\n';
        } else {
            if (have_one_edge) {
                cout << "Alice" << '\n';
            } else {
                cout << "Bob" << '\n';
            }
        }
    } else {
        cout << "Bob" << '\n';
    }

    return 0;
}