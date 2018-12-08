#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int N_MAX=100000;

int color[N_MAX];
vector<int> vec[N_MAX];

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < vec[v].size(); i++) {
        if (color[vec[v][i]] == c) return false;
        if (color[vec[v][i]] == 0 && !dfs(vec[v][i], -c)) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 0; i < m; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
    return 0;
}