#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int a[n], b[n];
    int amax = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        amax = max(amax, a[i]);
    }

    int ans = 0;
    sort(b, b+n, greater<int>());

    for (int i = 0; i < n; i++) {
        if (b[i] <= amax) {
            break;
        } else {
            h -= b[i];
            ans++;
            if (h <= 0) {
                cout << ans << endl;
                return 0;
            }
        }
    }

    while (h > 0) {
        h -= amax;
        ans++;
    }

    cout << ans << endl;
    return 0;
}