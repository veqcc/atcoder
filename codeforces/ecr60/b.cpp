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
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll m, k;
    cin >> n >> m >> k;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n, greater<int>());

    ll sm = k * a[0] + a[1];

    cout << m / (k + 1LL) * sm + m % (k+1) * a[0] << "\n";
    return 0;
}