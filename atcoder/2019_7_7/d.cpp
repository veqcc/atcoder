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

    int n;
    cin >> n;

    ll a[n];
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (i % 2 == 0) {
            tmp += a[i];
        } else {
            tmp -= a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << tmp << ' ';
        tmp = 2 * a[i] - tmp;
    }

    return 0;
}