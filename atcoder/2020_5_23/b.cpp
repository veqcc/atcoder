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
typedef pair<int, int> P;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;

    vector<int> p(n * n);
    for (int i = 0 ; i < n * n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<vector<bool>> exist(n, vector<bool>(n, true));
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = min(min(i, n - i - 1), min(j, n - j - 1));
        }
    }

    int ans = 0;
    for (int elm : p) {
        int i = elm / n;
        int j = elm % n;

        ans += s[i][j];
        exist[i][j] = false;

        queue<P> q;
        q.push({i, j});

        while (!q.empty()) {
            P val = q.front();
            q.pop();

            int x = val.first;
            int y = val.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0) continue;
                if (nx >= n || ny >= n) continue;
                if (s[nx][ny] <= s[x][y] + (exist[x][y] == true)) continue;

                s[nx][ny] = s[x][y] + (exist[x][y] == true);
                q.push({nx, ny});
            }
        }
    }

    cout << ans << endl;
    return 0;
}