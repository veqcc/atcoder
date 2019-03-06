#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
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
    cout.tie(0);

    int n;
    cin >> n;

    ll a[n];
    ll sm = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    int m;
    cin >> m;

    int q[m];
    for (int i = 0; i < m; i++) cin >> q[i];

    sort(a, a+n, greater<ll>());

    for (int i = 0; i < m; i++) {
        cout << sm - a[q[i] - 1] << "\n";
    }

    return 0;
}