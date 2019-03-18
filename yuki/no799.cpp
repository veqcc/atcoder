#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = (b - a + 1) * (d - c + 1);

    for (int i = a; i <= b; i++) {
        if (i >= c && i <= d) ans--;
    }

    cout << ans << "\n";
    return 0;
}