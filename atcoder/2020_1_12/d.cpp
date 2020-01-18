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

vector <int> dx = {1, -1, 0, 0};
vector <int> dy = {0, 0, 1, -1};

typedef pair <int, int> P;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    char s[h][w];
    for (int i = 0; i < h; i++) cin >> s[i];

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // start = (i, j)
            if (s[i][j] == '#') continue;

            vector < vector <int> > d(h, vector<int>(w, 100005));
            int start = i * w + j;
            priority_queue <P, vector<P>, greater<P>> q;
            q.push(P(0, start));

            while (q.size()) {
                P p = q.top();
                q.pop();

                if (d[p.second / w][p.second % w] <= p.first) continue;
                d[p.second / w][p.second % w] = p.first;

                for (int l = 0; l < 4; l++) {
                    int x = p.second / w + dx[l];
                    int y = p.second % w + dy[l];

                    if (x < 0 || x >= h) continue;
                    if (y < 0 || y >= w) continue;
                    if (s[x][y] == '#') continue;
                    if (d[x][y] <= p.first) continue;

                    q.push(P(p.first + 1, x * w + y));
                }
            }

            for (int k = 0; k < h; k++) {
                for (int l = 0; l < w; l++) {
                    if (d[k][l] < 100005) {
                        ans = max(ans, d[k][l]);
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}