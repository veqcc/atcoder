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

    int x[n], y[n];
    int mod = -1;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (mod == -1) {
            mod = (abs(x[i]) + abs(y[i])) % 2;
        } else if (mod != (abs(x[i]) + abs(y[i])) % 2) {
            mod = -2;
        }
    }

    if (mod == -2) {
        cout << -1 << "\n";
        return 0;
    }

    vector <int> D;
    if (mod == 0) D.push_back(1);
    for (int i = 30; i >= 0; i--) D.push_back(1 << i);

    cout << D.size() << "\n";
    for (int d : D) cout << d << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        int u = x[i] + y[i];
        int v = x[i] - y[i];

        for (int d : D) {
            if (u >= 0 && v >= 0) {
                cout << 'R';
                u -= d; v -= d;
            } else if (u >= 0 && v < 0) {
                cout << 'U';
                u -= d; v += d;
            } else if (u < 0 && v >= 0) {
                cout << 'D';
                u += d; v -= d;
            } else {
                cout << 'L';
                u += d; v += d;
            }
        }

        cout << "\n";
    }

    return 0;
}