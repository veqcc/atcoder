#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int N, C;
    cin >> N >> C;
    int D[C][C];
    int t[3][C];
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }

    fill(t[0], t[2]+C, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c;
            cin >> c;
            c--;
            t[(i+j)%3][c]++;
        }
    }

    int cost = 1000000007;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            if (i == j) continue;
            for (int k = 0; k < C; k++) {
                if (i == k || j == k) continue;

                int tmp = 0;
                for (int l = 0; l < C; l++) {
                    tmp += t[0][l] * D[l][i];
                }
                for (int l = 0; l < C; l++) {
                    tmp += t[1][l] * D[l][j];
                }
                for (int l = 0; l < C; l++) {
                    tmp += t[2][l] * D[l][k];
                }

                cost = min(cost, tmp);
            }
        }
     }

    cout << cost << "\n";
    return 0;
}