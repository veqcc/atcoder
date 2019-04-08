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

    vector <int> c(5, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }

    int ans = 0;

    ans += c[4];

    ans += c[3];
    c[1] -= c[3];

    ans += c[2] / 2;
    if (c[2] % 2 == 1) {
        ans += 1;
        c[1] -= 2;
    }

    c[1] = max(c[1], 0);

    ans += c[1] / 4;
    if (c[1] % 4 > 0) ans += 1;


    cout << ans << "\n";
    return 0;
}