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

    int n, x;
    cin >> n >> x;

    vector <int> a(n);
    int loss = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            loss++;
        } else {
            cur ^= a[i];
        }
    }

    if (loss == 0 && x != cur) {
        cout << -1 << "\n";
        return 0;
    }

    if ((x ^ cur) > x) {
        // need at least two -1
        if (loss < 2) {
            cout << -1 << "\n";
            return 0;
        }

        if (cur > x) {
            cout << -1 << "\n";
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                cout << a[i] << " ";
            } else {
                if (loss > 2) {
                    cout << 0 << " ";
                } else if (loss == 2) {
                    cout << cur << " ";
                } else {
                    cout << x << " ";
                }
                loss--;
            }
        }

        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            cout << a[i] << " ";
        } else {
            if (loss > 1) {
                cout << 0 << " ";
            } else {
                cout << (cur ^ x) << " ";
            }
            loss--;
        }
    }

    return 0;
}