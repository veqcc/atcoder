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

    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << 0 << '\n';
        return 0;
    }

    if (c == 1) {
        for (int i = 2; i <= r + 1; i++) {
            cout << i << '\n';
        }
        return 0;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = r + 1; j <= r + c; j++) {
            cout << i * j << ' ';
        }
        cout << '\n';
    }

    return 0;
}