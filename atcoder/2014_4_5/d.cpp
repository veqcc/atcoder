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

int LIS(vector <int> vec, bool is_strong = true) {
    const int INF = 1 << 30;
    int n = vec.size();
    vector <int> dp(n, INF);
    for (int i = 0; i < n; i++) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), vec[i]) = vec[i];
        else *upper_bound(dp.begin(), dp.end(), vec[i]) = vec[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    cout << n - LIS(c) << "\n";
    return 0;
}