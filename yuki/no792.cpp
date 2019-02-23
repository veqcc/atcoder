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
    cout.tie(0);

    int n;
    cin >> n;
    int m = 1 << n;
    bool q[m][n], r[m];
    bool all0 = true, all1 = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> q[i][j];
        }
        cin >> r[i];
        if (r[i]) all0 = false;
        else all1 = false;
    }

    cout << "A=";
    if (all0) {
        cout << "⊥";
        return 0;
    }
    if (all1) {
        cout << "⊤";
        return 0;
    }

    bool init = true;
    for (int i = 0; i < m; i++) {
        if (!r[i]) continue;

        if (init) {
            init = false;
        } else {
            cout << "∨";
        }
        cout << '(';
        bool ini = true;
        for (int j = 0; j < n; j++) {
            if (ini) {
                ini = false;
            } else {
                cout << "∧";
            }
            if (!q[i][j]) cout << "¬";
            cout << "P_" << to_string(j+1);
        }
        cout << ')';
    }

    return 0;
}