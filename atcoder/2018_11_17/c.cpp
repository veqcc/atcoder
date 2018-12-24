#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, m, tmp;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n);

    cin >> m;
    int t[m];
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < m; i++) {
        tmp = lower_bound(a, a+n, t[i]) - a;
        if (tmp == 0) {
            cout << b[tmp] << endl;
        } else if (tmp == n) {
            cout << b[tmp-1] + t[i] - a[tmp-1] << endl;
        } else {
            cout << min(b[tmp], b[tmp-1] + t[i] - a[tmp-1]) << endl;
        }
    }

    return 0;
}