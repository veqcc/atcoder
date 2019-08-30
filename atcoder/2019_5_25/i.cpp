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
const int MAX = 1 << 30;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int A = 1, B = 0, idx = -1;
    for (int i = 0; i < n; i++)  {
        int die1 = (A + b[i] - 1) / b[i];
        int die2 = B == 0 ? MAX : (a[i] + B - 1) / B;

        if (die1 < die2) {
            A = a[i], B = b[i], idx = i;
        } else if (die1 == die2) {
            A = 1, B = 0, idx = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == idx) continue;

        int die1 = (A + b[i] - 1) / b[i];
        int die2 = B == 0 ? MAX : (a[i] + B - 1) / B;

        if (die1 <= die2) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << idx + 1 << "\n";
    return 0;
}