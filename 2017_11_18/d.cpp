#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int H, W, c[10][10], tmp, minc[10], ans=0;

int main() {
    cin >> H >> W;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> c[i][j];
        minc[i] = c[i][1];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                minc[j] = min(minc[j], c[j][k]+minc[k]);
            }
        }
    }

    for (int i = 0; i < H*W; i++) {
        cin >> tmp;
        if (tmp != -1) ans += minc[tmp];
    }

    cout << ans << endl;
    return 0;
}