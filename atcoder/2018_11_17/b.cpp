#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, m, r, ans = 0;
    cin >> n >> m;
    double p=1;
    for (int i = 1; i <= n; i++) {
        p = p * i / m;
        while (p < 1) {
            p *= 10;
            ans++;
        }
        while (p >= 10) {
            p /= 10;
            ans--;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> r;
        for (int i = 1; i <= r; i++) {
            p /= i;
            while (p < 1) p *= 10, ans++;
        }
    }

    cout << ans << endl;
    return 0;
}