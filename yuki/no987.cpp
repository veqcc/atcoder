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
    cin >> n >> m;

    char op;
    cin >> op;

    vector <ll> a(n), b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (op == '+') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i] + b[j] << ' ';
            }
            cout << '\n';
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i] * b[j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}