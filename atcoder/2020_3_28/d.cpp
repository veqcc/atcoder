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

    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    vector <int> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dis = min(j - i, abs(i - x) + 1 + abs(j - y));
            ans[dis]++;
        }
    }

    for (int i = 1; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}