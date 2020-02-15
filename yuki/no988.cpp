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

    int n, m;
    ll k;
    cin >> n >> m >> k;

    char op;
    cin >> op;

    vector <ll> a(n), b(m);
    ll sum_a = 0, sum_b = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sum_b = (sum_b + b[i]) % k;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a = (sum_a + a[i]) % k;
    }

    if (op == '+') {
        cout << (sum_a * m + sum_b * n) % k << '\n';
    } else {
        cout << sum_a * sum_b % k << '\n';
    }

    return 0;
}