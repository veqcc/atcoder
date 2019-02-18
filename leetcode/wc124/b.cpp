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

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();

        bool possible[h][w];
        int table[h][w];
        queue <P> q;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 0) {
                    possible[i][j] = false;
                } else if (grid[i][j] == 1) {
                    possible[i][j] = true;
                    table[i][j] = 100000;
                } else {
                    possible[i][j] = true;
                    table[i][j] = 0;
                    q.push(P(i,j));
                }
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int mx = 0;

        while (q.size()) {
            P p = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if (y < 0 || y >= w || x < 0 || x >= h) continue;
                if (!possible[x][y]) continue;
                if (table[x][y] > table[p.first][p.second] + 1) {
                    table[x][y] = table[p.first][p.second] + 1;
                    mx = max(mx, table[x][y]);
                    q.push(P(x, y));
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (table[i][j] == 100000) {
                    mx = -1;
                    break;
                }
            }
        }

        return mx;
    }
};

int main() {
    Solution so;

    vector<vector<int>> vec = {
            {2,1,1},
            {1,1,0},
            {0,1,1}
    };

    cout << so.orangesRotting(vec) << "\n";
    return 0;
}