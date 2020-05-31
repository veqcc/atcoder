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
const ll MAX = 1000000000000000000LL;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll sum = 1;
    for (int i = 0; i < n; i++) {
        if (sum <= MAX / a[i]) {
            sum *= a[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << sum << endl;
    return 0;
}