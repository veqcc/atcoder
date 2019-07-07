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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    int x[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> x[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int dis = 0;
            for (int k = 0; k < d; k++) {
                dis += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }

            if ((int)sqrt(dis) * (int)sqrt(dis) == dis) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}