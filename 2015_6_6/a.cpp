#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

bool visited[500][500];
int c[500][500];
int H, W;

void dfs(int h, int w) {
    visited[h][w] = true;
    if (h > 0 && c[h-1][w] == '.' && !visited[h-1][w]) {
        dfs(h-1, w);
    }
    if (h < H-1 && c[h+1][w] == '.' && !visited[h+1][w]) {
        dfs(h+1, w);
    }
    if (w > 0  && c[h][w-1] == '.' && !visited[h][w-1]) {
        dfs(h, w-1);
    }
    if (w < W-1 && c[h][w+1] == '.' && !visited[h][w+1]) {
        dfs(h, w+1);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int sh, sw, gh, gw;
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < W; j++) {
            if (s[j] == 's') {
                sh = i;
                sw = j;
                c[i][j] = '.';
            } else if (s[j] == 'g') {
                gh = i;
                gw = j;
                c[i][j] = '.';
            } else {
                c[i][j] = s[j];
            }
        }
    }

    dfs(sh, sw);

    if (visited[gh][gw]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}