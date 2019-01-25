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

    ll n;
    cin >> n;
    ll n_sum = n * (n + 1) / 2;

    ll a[n+1], a_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_sum += a[i];
    }
    a[n] = a[0];

    ll c;
    if (a_sum % n_sum != 0) {
        cout << "NO" << endl;
        return 0;
    } else {
        c = a_sum / n_sum;
    }

    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + c == a[i+1]) {
            continue;
        } else if (a[i] + c < a[i+1]) {
            cout << "NO" << endl;
            return 0;
        } else {
            count += (a[i] + c - a[i+1]) / n;
            if ((a[i] + c - a[i+1]) % n != 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (count != c) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << "\n";
    return 0;
}