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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, d;
    cin >> m >> d;

    int ans = 0;
    for (int i = 4; i <= m; i++) {
        for (int j = 2; j < 10; j++) {
            for (int k = 2; k < 10; k++) {
                if (j * 10 + k <= d) {
                    if (i == j * k) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}