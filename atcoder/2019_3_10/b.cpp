#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int inf = 1 << 30;
const int cost[10] = {0,0,0,0,0,0,1,1,2,3};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W;
    cin >> H >> W;

    int A[H][W];
    bool all_zero = true;
    bool exist_five = false;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> A[h][w];
            if (A[h][w]) all_zero = false;
            if (A[h][w] == 5) exist_five = true;
        }
    }

    if (!exist_five && !all_zero) {
        cout << "No\n";
        return 0;
    }

    int ret = inf;

    if (H == 1) {
        for (int i = 0; i < W; i++) {
            if (A[0][i] == 5) {
                int c = 1;

                int mx = 0;
                for (int j = 0; j < i; j++) mx = max(mx, A[0][j]);
                c += cost[mx];

                mx = 0;
                for (int j = i+1; j < W; j++) mx = max(mx, A[0][j]);
                c += cost[mx];

                ret = min(ret, c);
            }
        }
    } else if (W == 1) {
        for (int i = 0; i < H; i++) {
            if (A[i][0] == 5) {
                int c = 1;

                int mx = 0;
                for (int j = 0; j < i; j++) mx = max(mx, A[j][0]);
                c += cost[mx];

                mx = 0;
                for (int j = i+1; j < H; j++) mx = max(mx, A[j][0]);
                c += cost[mx];

                ret = min(ret, c);
            }
        }
    } else {
        int mx = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                mx = max(mx, A[i][j]);
            }
        }

        ret = 1 + cost[mx];
    }

    if (all_zero) ret = 0;
    cout << "Yes " << ret << "\n";
    return 0;
}