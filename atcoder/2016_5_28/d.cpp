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
typedef pair <int, int> P;

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

    vector <P> wh(n);
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        wh[i] = {w, h};
    }

    sort(wh.begin(), wh.end(), [&](const P &a, const P &b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });

    vector <int> h(n);
    for (int i = 0; i < n; i++) h[i] = wh[i].second;

    cout << LIS(h) << "\n";
    return 0;
}