#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
const int MAX_N=100, MAX_M=100;

int N, M;
char field[MAX_N+2][MAX_M+2];

void dfs(int x, int y) {
    field[x][y] = '.';
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (field[x+i][y+j] == 'W') {
                dfs(x+i, y+j);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    fill(field[0], field[MAX_N+1] + MAX_M+2, '.');

    for (int n = 1; n <= N; n++) {
        string s;
        cin >> s;
        for (int m = 0; m < M; m++) {
            field[n][m+1] = s[m];
        }
    }

    int res = 0;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            if (field[n][m] == 'W') {
                dfs(n, m);
                res++;
            }
        }
    }

    cout << res << "\n";
    return 0;
}