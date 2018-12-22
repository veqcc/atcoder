#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    int i, j, n, ans[100];
    cin >> n;
    for (i = 0; i < n; i += 5) {
        cout << "? ";
        for (j = 0; j < n; j++) {
            if (j - i < 5 && j - i >= 0) {
                cout << pow(10, j % 5) << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;

        int x, y = 0;
        cin >> x;
        while (x > 0) {
            int k = x % 10;
            if (k == 8) x -= 8;
            if (k == 9) x -= 9;
            if (k == 0) x -= 10;
            if (k == 1) x -= 11;
            if (k == 2) x -= 12;
            ans[i + y] = k;
            x /= 10;
            y++;
        }
    }
    cout << "! ";
    for (i = 0; i < n; i++) {
        cout << ans[i] % 2 << " ";
    }
    cout << endl;
    return 0;
}