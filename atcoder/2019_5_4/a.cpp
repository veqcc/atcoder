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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    string s[1005];
    for (int i = 0; i < h; i++) cin >> s[i];

    priority_queue <P, vector<P>, greater<P>> q;
    int c[h][w];
    fill(c[0], c[h], 1e9);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                q.push(P(0, i * w + j));
                c[i][j] = 0;
            }
        }
    }

    while (q.size()) {
        P p = q.top();
        q.pop();

        int cost = p.first;
        if (cost > c[p.second / w][p.second % w]) continue;

        for (int i = 0; i < 4; i++) {
            int x = p.second / w + dx[i];
            int y = p.second % w + dy[i];
            if (x < 0 || x >= h || y < 0 || y >= w) continue;

            if (c[x][y] > cost + 1) {
                c[x][y] = cost + 1;
                q.push(P(cost + 1, x * w + y));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = max(ans, c[i][j]);
        }
    }

    cout << ans << "\n";
    return 0;
}