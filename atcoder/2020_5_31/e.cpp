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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (n % 2 == 1) {
        cout << b[n / 2] - a[n / 2] + 1 << endl;
    } else {
        ll upper = (2 * b[n / 2] + 2 * b[n / 2 - 1]) / 2;
        ll lower = (2 * a[n / 2] + 2 * a[n / 2 - 1]) / 2;
        cout << upper - lower + 1 << endl;
    }

    return 0;
}