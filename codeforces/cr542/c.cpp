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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, r1, c1, r2, c2, earth[50][50];

vector <P> bfs(int r, int c) {
    queue <P> q;
    q.push(P(r, c));

    bool visited[n][n];
    fill(visited[0], visited[n], false);
    visited[r][c] = true;

    vector <P> ret;
    while (q.size()) {
        P p = q.front();
        q.pop();
        ret.push_back(p);

        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (earth[x][y]) continue;
                if (visited[x][y]) continue;
                q.push(P(x, y));
                visited[x][y] = true;
            }
        }
    }

    return ret;
}

int main() {
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            earth[i][j] = s[j] - '0';
        }
    }

    vector <P> st = bfs(r1, c1);
    vector <P> en = bfs(r2, c2);

    int ans = 1 << 30;
    for (P u : st) {
        for (P v : en) {
            int x = abs(u.first - v.first);
            int y = abs(u.second - v.second);
            ans = min(ans, x * x + y * y);
        }
    }

    cout << ans << "\n";
    return 0;
}
