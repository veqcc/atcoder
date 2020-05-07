#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair <int, int> P;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int r, c;
    cin >> r >> c;

    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;

    vector<string> table(r);
    for (int i = 0; i < r; i++) cin >> table[i];

    vector<vector<int>> dist(r, vector<int>(c, r * c));
    dist[sy][sx] = 0;

    queue<P> q;
    q.push({sy, sx});

    while (!q.empty()) {
        P cur = q.front();
        q.pop();

        int y = cur.first;
        int x = cur.second;

        for (int i = 0; i < 4; i++) {
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            if (table[next_y][next_x] == '#') continue;
            if (dist[next_y][next_x] == r * c) {
                dist[next_y][next_x] = dist[y][x] + 1;
                q.push({next_y, next_x});
            }
        }
    }

    cout << dist[gy][gx] << "\n";
    return 0;
}