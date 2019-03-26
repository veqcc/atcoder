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
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int r, c;
        cin >> r >> c;

        priority_queue < P, vector<P>, greater<P> > q;
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < c; j++) {
                if (s[j] - '0' == 1) {
                    q.push(P(0, i*c+j));
                }
            }
        }

        int dis[r][c];
        fill(dis[0], dis[r], INF);

        while (q.size()) {
            P p = q.top();
            q.pop();

            int cost = p.first;
            int x = p.second / c;
            int y = p.second % c;

            if (dis[x][y] <= cost) continue;
            dis[x][y] = cost;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (dis[nx][ny] <= cost) continue;
                q.push(P(cost + 1, nx * c + ny));
            }
        }

        vector <P> cost(r * c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cost[i * c + j] = P(dis[i][j], i * c + j);
            }
        }

        sort(cost.begin(), cost.end(), greater<P>());

        int left = -1, right = r * c;
        while (right - left > 1) {
            int k = (left + right) / 2;

            if (cost[0].first <= k) {
                right = k;
                continue;
            }

            int max_sum = -INF, min_sum = INF, max_dif = -INF, min_dif = INF;
            for (P p : cost) {
                if (p.first <= k) break;
                int x = p.second / c;
                int y = p.second % c;
                max_sum = max(max_sum, y + x);
                min_sum = min(min_sum, y + x);
                max_dif = max(max_dif, y - x);
                min_dif = min(min_dif, y - x);
            }

            if (max_sum - min_sum > 2*k || max_dif - min_dif > 2*k) {
                left = k;
            } else if (max_sum - min_sum == 2*k && max_dif - min_dif == 2*k && (min_sum + min_dif) % 2 == 1) {
                left = k;
            } else {
                right = k;
            }
        }

        cout << "Case #" << t+1 << ": " << right << '\n';
    }

    return 0;
}