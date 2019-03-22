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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    while (true) {
        if (a == 0) break;
        if (b < c) break;
        if (d < 1 + c) break;

        a--;
        b -= c;
        d -= 1 + c;

        ans++;
    }

    cout << ans << "\n";
    return 0;
}