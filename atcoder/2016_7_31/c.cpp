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

    int n;
    ll l;
    cin >> n >> l;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll mx = 0;
    int mx_idx = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i+1] > mx) {
            mx = a[i] + a[i+1];
            mx_idx = i + 1;
        }
    }

    if (mx < l) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for (int i = 1; i < mx_idx; i++) {
            cout << i << "\n";
        }
        for (int i = n-1; i > mx_idx; i--) {
            cout << i << "\n";
        }
        cout << mx_idx << "\n";
    }

    return 0;
}