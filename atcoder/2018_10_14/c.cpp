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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    bool sprayed[n + 2][n + 2];
    fill(sprayed[0], sprayed[n + 2], false);

    char ans[n + 2][n + 2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][j] = '.';

            if ((i + 2 * j) % 5 == 0) {
                ans[i][j] = 'X';
                sprayed[i][j] = true;
                sprayed[i - 1][j] = true;
                sprayed[i + 1][j] = true;
                sprayed[i][j - 1] = true;
                sprayed[i][j + 1] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!sprayed[i][j]) {
                cout << 'X';
            } else {
                cout << ans[i][j];
            }
        }
        cout << "\n";
    }

    return 0;
}