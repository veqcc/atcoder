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
typedef pair <int, int> P;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin >> r >> c;

    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;

    vector <string> table(r);
    for (int i = 0; i < r; i++) cin >> table[i];

    vector<vector<int>> dp(r, vector<int>(c, r * c));
    dp[sy][sx] = 0;
    queue <P> q;

    q.push(P(sy * c + sx, 0));

    while (q.size()) {
        P p = q.front();
        q.pop();

        int y = p.first / c;
        int x = p.first % c;
        int n = p.second;
        if (dp[y][x] < n) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0) continue;
            if (ny >= r || nx >= c) continue;
            // if (table[ny][nx] == '#') continue;

            if (dp[ny][nx] > n + 1) {
                dp[ny][nx] = n + 1;
                q.push(P(ny * c + nx, n + 1));
            }
        }
    }

    cout << dp[gy][gx] << endl;
    return 0;
}