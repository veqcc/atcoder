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

    int n;
    cin >> n;

    int cur = 0;
    int no_use = -1;
    int i = 1;
    for (; i <= n; i++) {
        cur += i;
        if (cur >= n) {
            no_use = cur - n;
            break;
        }
    }

    for (int j = 1; j <= i; j++) {
        if (j != no_use) cout << j << '\n';
    }

    return 0;
}