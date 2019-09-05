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

int n, m;

bool dfs(vector<vector<bool>> &pass, int i, int j) {
    if (i == n - 1 && j == m - 1) return true;
    if (!pass[i][j]) return false;

    pass[i][j] = false;
    if (i < n - 1 && dfs(pass, i + 1, j)) return true;
    if (j < m - 1 && dfs(pass, i, j + 1)) return true;

    return false;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<vector<bool>> pass(n, vector<bool>(m, true));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                pass[i][j] = false;
            }
        }
    }

    bool possible = dfs(pass, 0, 0);
    if (!possible) {
        cout << 0 << '\n';
        return 0;
    }

    pass[0][0] = pass[n - 1][m - 1] = true;
    possible = dfs(pass, 0, 0);
    if (possible) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }

    return 0;
}