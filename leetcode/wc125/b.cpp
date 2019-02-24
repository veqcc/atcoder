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

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rx, ry;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                }
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int cnt = 0;

        for (int i = 0; i < 4; i++) {
            int x = rx + dx[i], y = ry + dy[i];

            while (true) {
                if (x < 0 || x > 7 || y < 0 || y > 7) break;
                if (board[x][y] == 'B') break;
                if (board[x][y] == 'p') {
                    cnt++;
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }

        return cnt;
    }
};

int main() {
    return 0;
}