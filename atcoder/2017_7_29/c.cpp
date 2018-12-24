#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, m, ta, tb;
    cin >> n >> m;
    bool a[n], b[n];
    fill(a, a+n, false);
    fill(b, b+n, false);
    for (int i = 0; i < m; i++) {
        cin >> ta >> tb;
        if (ta == 1) a[tb-1] = true;
        if (ta == n) b[tb-1] = true;
        if (tb == 1) a[ta-1] = true;
        if (tb == n) b[ta-1] = true;
    }

    for (int i = 1; i < n-1; i++) {
        if (a[i] && b[i]) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}