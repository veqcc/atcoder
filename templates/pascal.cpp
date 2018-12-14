#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

ll C[51][51];

void comb_table(int N) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1LL;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
}

int main() {

    comb_table(50);

    cout << C[6][3] << "\n"; // 6C3 = 20
    cout << C[50][25] << "\n"; // 50C25

    return 0;
}