#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int maxi = max(A, max(B, C));
    int sumu = maxi * 3 - A - B - C;
    int ans = 0;

    if (sumu % 2 == 0) {
        ans = sumu / 2;
    } else {
        ans = sumu / 2 + 2;
    }

    cout << ans << endl;
    return 0;
}