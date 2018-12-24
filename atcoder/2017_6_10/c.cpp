#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    int a[9];
    fill(a, a+9, 0);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp >= 3200) a[8]++;
        else a[tmp/400]++;
    }

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        if (a[i] > 0) ans++;
    }

    if (ans == 0) {
        cout << 1 << " " << a[8] << endl;
    } else {
        cout << ans << " " << ans + a[8] << endl;
    }

    return 0;
}