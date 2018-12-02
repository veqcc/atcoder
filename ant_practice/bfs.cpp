#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int INF=100000000, MAX_N=100, MAX_M=100;
typedef pair<int, int> P;

char maze[MAX_N+2][MAX_M+2];
int N, M, sx, sy, gx, gy;
int d[MAX_N+2][MAX_M+2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(P sp) {
    queue<P> q;
    q.push(sp);

    while (q.size()) {
        P p = q.front();
        q.pop();
        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++) {
            int next_x = p.first + dx[i];
            int next_y = p.second + dy[i];
            if (maze[next_x][next_y] == '.' && d[next_x][next_y] == INF) {
                q.push(make_pair(next_x, next_y));
                d[next_x][next_y] = d[p.first][p.second] + 1;
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    fill(maze[0], maze[MAX_N+1]+MAX_M+2, '#');
    fill(d[0], d[MAX_N+1]+MAX_M+2, INF);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'S') {
                sx = i+1; sy = j+1; s[j] = '.';
            } else if (s[j] == 'G') {
                gx = i+1, gy = j+1; s[j] = '.';
            }
            maze[i+1][j+1] = s[j];
        }
    }

    d[sx][sy] = 0;
    bfs(make_pair(sx, sy));

    cout << d[gx][gy] << "\n";
    return 0;
}