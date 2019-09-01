#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

const int dx[4] = {1, 1, 0, 0};
const int dy[4] = {1, 0, 1, 0};
const int radius[2] = {100, 150};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    for (int r : radius) {
        int ans = 0;
        for (int i = 0; i < 2 * r / k; i++) {
            for (int j = 0; j < 2 * r / k; j++) {
                bool in = true;
                for (int l = 0; l < 4; l++) {
                    int x = -r + k * (i + dx[l]);
                    int y = -r + k * (j + dy[l]);
                    if (x * x + y * y > r * r) in = false;
                }
                if (in) ans++;
            }
        }
        cout << ans << ' ';
    }

    return 0;
}