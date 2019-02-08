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

    int c[2][n];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    if (c[0][0] != c[1][0] || c[0][n-1] != c[1][n-1]) {
        cout << "No\n";
        return 0;
    }

    int diff[2][n-1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n-1; j++) {
            diff[i][j] = c[i][j+1] - c[i][j];
        }
        sort(diff[i], diff[i]+n-1);
    }

    for (int i = 0; i < n-1; i++) {
        if (diff[0][i] != diff[1][i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}