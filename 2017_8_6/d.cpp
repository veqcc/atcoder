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

    int H, W, N;
    cin >> H >> W >> N;
    int count = 0;
    int hw[H][W];
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        for (int j = count; j < count + a; j++) {
            hw[j/W][j%W] = i;
        }
        count += a;
    }

    for (int i = 0; i < H; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < W; j++) {
                cout << hw[i][j] << " ";
            }
            cout << "\n";
        } else {
            reverse(hw[i], hw[i]+W);
            for (int j = 0; j < W; j++) {
                cout << hw[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}