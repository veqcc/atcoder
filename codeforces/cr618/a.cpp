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

    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector <int> bit(30);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if (a[i] & (1 << j)) {
                bit[j]++;
            }
        }
    }

    int mx = 0, mx_idx = 0;
    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (int j = 0; j < 30; j++) {
            if (bit[j] == 1 && (a[i] & (1 << j))) {
                sm += (1 << j);
            }
        }

        if (sm > mx) {
            mx = sm;
            mx_idx = i;
        }
    }

    cout << a[mx_idx] << ' ';

    for (int i = 0; i < n; i++) {
        if (i == mx_idx) continue;
        cout << a[i] << ' ';
    }

    cout << "\n";
    return 0;
}