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
typedef long double ld;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ld w, h, x, y;
    cin >> w >> h >> x >> y;

    cout << w * h / 2 << " ";

    if (x == w / 2 && y == h / 2) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}