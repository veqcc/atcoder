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
typedef long double ld;
typedef unsigned int uint;
using namespace std;

ll a[100005];

int main() {
    ll n, k, m, i, sm=0, tmp;
    ld mx;
    cin >> n >> k >> m;

    for (i = 1; i <= n; i++) {
        cin >> a[i];
        sm += a[i];
    }

    sort(a+1, a+n+1);

    mx = (ld)(sm + min(m, n*k)) / (ld)n;

    for (i = 1; i <= min(m, n-1); i++) {
        sm -= a[i];
        tmp = sm + min(m-i, (n-i)*k);\
        mx = max(mx, (ld)tmp / (ld)(n-i));
    }

    cout << fixed << setprecision(20) << mx << endl;
    return 0;
}