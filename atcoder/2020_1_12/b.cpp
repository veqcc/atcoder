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

    int n, k, m;
    cin >> n >> k >> m;

    int sm = 0;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        sm += a;
    }

    if (sm < n * m - k) {
        cout << -1 << '\n';
    } else {
        cout << max(0, n * m - sm) << '\n';
    }

    return 0;
}