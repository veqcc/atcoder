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
typedef pair<int, int> P;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> sum(m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum[j] += a[i][j];
        }
    }

    vector<P> point(n);
    for (int i = 0; i < n; i++) {
        point[i].second = i;
        for (int j = 0; j < m; j++) {
            point[i].first += a[i][j] * sum[j];
        }
    }

    sort(point.begin(), point.end(), greater<P>());

    vector<int> x(m), y(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0) {
                x[j] += a[point[i].second][j];
            } else {
                y[j] += a[point[i].second][j];
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j < m; j++) {
        ans += x[j] * x[j];
        ans -= y[j] * y[j];
    }

    cout << ans << endl;
    return 0;
}