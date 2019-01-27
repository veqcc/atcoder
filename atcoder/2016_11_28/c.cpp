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

    int n;
    cin >> n;
    int a[n];
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
        a[i] = a[i] ^ (a[i] - 1);
    }

    int ret = 0;
    for (int k = 30; k > 0; k--) {
        if (!(x & (1 << (k-1)))) continue;

        for (int i = 0; i < n; i++) {
            if (a[i] == (1 << k) - 1) {
                x ^= (1 << k) - 1;
                ret++;
                a[i] = 0;
                break;
            }
        }
    }

    cout << (x > 0 ? -1 : ret) << "\n";
    return 0;
}
