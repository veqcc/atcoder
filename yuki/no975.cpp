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

    int x, n, m;
    cin >> x >> n >> m;

    bool is_MrMax = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == x) is_MrMax = true;
    }

    bool is_MaxValue = false;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if (b == x) is_MaxValue = true;
    }

    if (is_MrMax && is_MaxValue) {
        cout << "MrMaxValu" << '\n';
    } else if (is_MrMax) {
        cout << "MrMax" << '\n';
    } else if (is_MaxValue) {
        cout << "MaxValu" << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}