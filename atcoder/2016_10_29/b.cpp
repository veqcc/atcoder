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
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        return 0;
    }

    int ans[2 * n - 1];
    fill(ans, ans+2*n-1, 0);

    ans[n-2] = x-1;
    ans[n-1] = x;
    ans[n] = x+1;

    int count = 1;
    if (x < n) {
        ans[n-3] = x+2;
        ans[n+1] = x+3;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (count == x-1) count = x+4;
            if (ans[i] == 0) {
                ans[i] = count;
                count++;
            }
        }
    } else if (x > n) {
        ans[n - 3] = x - 3;
        ans[n + 1] = x - 2;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (count == x - 3) count = x + 2;
            if (ans[i] == 0) {
                ans[i] = count;
                count++;
            }
        }
    } else if (x == n) {
        for (int i = 0; i < 2 * n - 1; i++) {
            if (count == x-1) count = x+2;
            if (ans[i] == 0) {
                ans[i] = count;
                count++;
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < 2*n-1; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}