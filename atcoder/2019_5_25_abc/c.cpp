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

    int n, m;
    cin >> n >> m;

    int lmax = 0, rmin = n;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        lmax = max(l, lmax);
        rmin = min(r, rmin);
    }

    cout << max(rmin - lmax + 1, 0) << "\n";
    return 0;
}